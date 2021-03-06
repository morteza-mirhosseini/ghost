/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 *  Ghost, a micro-kernel based operating system for the x86 architecture    *
 *  Copyright (C) 2015, Max Schlüssel <lokoxe@gmail.com>                     *
 *                                                                           *
 *  This program is free software: you can redistribute it and/or modify     *
 *  it under the terms of the GNU General Public License as published by     *
 *  the Free Software Foundation, either version 3 of the License, or        *
 *  (at your option) any later version.                                      *
 *                                                                           *
 *  This program is distributed in the hope that it will be useful,          *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU General Public License for more details.                             *
 *                                                                           *
 *  You should have received a copy of the GNU General Public License        *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GHOSTLIBRARY_UI_MOUSELISTENER
#define GHOSTLIBRARY_UI_MOUSELISTENER

#include <ghostuser/ui/listener.hpp>
#include <cstdint>

/**
 *
 */
class g_mouse_listener: public g_listener {
public:
	virtual ~g_mouse_listener() {
	}

	virtual void process(g_ui_component_event_header* header) {
		g_ui_component_mouse_event* event = (g_ui_component_mouse_event*) header;
		handle_mouse_event(event);
	}

	virtual void handle_mouse_event(g_ui_component_mouse_event* e) = 0;
};

#endif
