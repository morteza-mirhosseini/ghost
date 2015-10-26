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

#ifndef __ACTION_COMPONENT__
#define __ACTION_COMPONENT__

#include <ghost.h>
#include <string>
#include <list>
#include <ghostuser/ui/interface_specification.hpp>

/**
 * An action component is capable of being observed by an action listener.
 * The component may fire actions which are dispatched to the registered
 * listener for processing.
 */
class action_component_t {
private:
	g_tid target_thread;
	g_ui_component_id component_id;

public:
	/**
	 *
	 */
	action_component_t() :
			target_thread(-1), component_id(-1) {
	}

	/**
	 *
	 */
	virtual ~action_component_t() {
	}

	/**
	 *
	 */
	virtual void setActionListener(g_tid target_thread, g_ui_component_id component_id);

	/**
	 *
	 */
	virtual void fireAction();
};

#endif
