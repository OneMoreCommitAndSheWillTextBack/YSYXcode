/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <memory/consistency.h>
#include <memory/paddr.h>

static consistency_reservation_t *active_reservation = NULL;

static inline bool range_overlap(paddr_t lhs, int lhs_len, paddr_t rhs,
                                 int rhs_len) {
  uint64_t lhs_beg = (uint64_t)lhs;
  uint64_t lhs_end = lhs_beg + (uint64_t)lhs_len - 1;
  uint64_t rhs_beg = (uint64_t)rhs;
  uint64_t rhs_end = rhs_beg + (uint64_t)rhs_len - 1;
  return !(lhs_end < rhs_beg || rhs_end < lhs_beg);
}

static inline void reservation_clear(consistency_reservation_t *reservation) {
  if (reservation != NULL) {
    reservation->valid = false;
  }
  if (active_reservation == reservation) {
    active_reservation = NULL;
  }
}

word_t consistency_read(paddr_t addr, int len) {
  return paddr_read(addr, len);
}

void consistency_write(paddr_t addr, int len, word_t data) {
  paddr_write(addr, len, data);
}

word_t consistency_lr(consistency_reservation_t *reservation, paddr_t addr,
                      int len) {
  assert(reservation != NULL);
  assert(len > 0);

  if (active_reservation != NULL && active_reservation != reservation) {
    reservation_clear(active_reservation);
  }

  reservation->addr = addr;
  reservation->len = len;
  reservation->valid = true;
  active_reservation = reservation;

  return consistency_read(addr, len);
}

bool consistency_sc(consistency_reservation_t *reservation, paddr_t addr,
                    int len, word_t data) {
  assert(reservation != NULL);
  assert(len > 0);

  bool success = active_reservation == reservation && reservation != NULL &&
                 reservation->valid && reservation->addr == addr &&
                 reservation->len == len;

  if (active_reservation != NULL) {
    reservation_clear(active_reservation);
  }
  reservation_clear(reservation);

  if (!success) {
    return false;
  }

  consistency_write(addr, len, data);
  return true;
}

void consistency_invalidate(paddr_t addr, int len) {
  assert(len > 0);

  if (active_reservation == NULL || !active_reservation->valid) {
    return;
  }

  if (range_overlap(active_reservation->addr, active_reservation->len, addr,
                    len)) {
    reservation_clear(active_reservation);
  }
}
