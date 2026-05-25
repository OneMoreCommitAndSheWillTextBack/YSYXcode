/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of the Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#ifndef __MEMORY_CONSISTENCY_H__
#define __MEMORY_CONSISTENCY_H__

#include <common.h>

typedef struct {
  paddr_t addr;
  int len;
  bool valid;
} consistency_reservation_t;

word_t consistency_read(paddr_t addr, int len);
void consistency_write(paddr_t addr, int len, word_t data);

word_t consistency_lr(consistency_reservation_t *reservation, paddr_t addr,
                      int len);
bool consistency_sc(consistency_reservation_t *reservation, paddr_t addr,
                    int len, word_t data);

void consistency_invalidate(paddr_t addr, int len);

#endif
