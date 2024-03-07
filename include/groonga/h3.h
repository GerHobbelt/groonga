/*
  Copyright (C) 2024  Sutou Kouhei <kou@clear-code.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

GRN_API uint64_t
grn_h3_compute_cell(grn_ctx *ctx,
                    grn_geo_point *geo_point,
                    int32_t resolution,
                    const char *tag);
GRN_API grn_rc
grn_h3_compute_grid_disk(grn_ctx *ctx,
                         grn_geo_point *geo_point,
                         int32_t resolution,
                         int32_t k,
                         grn_obj *h3_indices,
                         const char *tag);

#ifdef __cplusplus
}
#endif
