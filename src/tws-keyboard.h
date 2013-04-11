/*
 * test-wayland-surface
 *
 * An example Wayland compositor using Clutter
 *
 * Copyright (C) 2013  Intel Corporation.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __TWS_KEYBOARD_H__
#define __TWS_KEYBOARD_H__

#include <clutter/clutter.h>
#include <wayland-server.h>

#include <xkbcommon/xkbcommon.h>

typedef struct
{
  struct xkb_keymap *keymap;
  int keymap_fd;
  size_t keymap_size;
  char *keymap_area;
  xkb_mod_index_t shift_mod;
  xkb_mod_index_t caps_mod;
  xkb_mod_index_t ctrl_mod;
  xkb_mod_index_t alt_mod;
  xkb_mod_index_t mod2_mod;
  xkb_mod_index_t mod3_mod;
  xkb_mod_index_t super_mod;
  xkb_mod_index_t mod5_mod;
} TwsXkbInfo;

typedef struct
{
  struct wl_keyboard parent;

  struct wl_display *display;

  struct xkb_context *xkb_context;

  TwsXkbInfo xkb_info;
  struct xkb_rule_names xkb_names;

  struct wl_keyboard_grab input_method_grab;
  struct wl_resource *input_method_resource;

  ClutterModifierType last_modifier_state;
} TwsKeyboard;

gboolean
tws_keyboard_init (TwsKeyboard *keyboard,
                   struct wl_display *display);

void
tws_keyboard_handle_event (TwsKeyboard *keyboard,
                           const ClutterKeyEvent *event);

void
tws_keyboard_release (TwsKeyboard *keyboard);

#endif /* __TWS_KEYBOARD_H__ */