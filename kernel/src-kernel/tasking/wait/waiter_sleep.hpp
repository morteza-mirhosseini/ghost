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

#ifndef GHOST_MULTITASKING_WAIT_MANAGER_SLEEP
#define GHOST_MULTITASKING_WAIT_MANAGER_SLEEP

#include <tasking/wait/waiter.hpp>
#include <tasking/tasking.hpp>
#include <logger/logger.hpp>

/**
 *
 */
class g_waiter_sleep: public g_waiter {
private:
	uint64_t time_start;
	uint64_t time_sleep;
	g_scheduler* timing_scheduler;

public:
	g_waiter_sleep(g_thread* task, uint64_t ms) {
		time_sleep = ms;
		timing_scheduler = task->scheduler;
		time_start = timing_scheduler->getMilliseconds();
	}

	/**
	 *
	 */
	virtual bool checkWaiting(g_thread* task) {

		uint64_t diff = timing_scheduler->getMilliseconds() - time_start;
		if (diff < time_sleep) {
			// Keep sleeping
			return true;
		}

		return false;
	}

	/**
	 *
	 */
	virtual const char* debug_name() {
		return "sleep";
	}

};

#endif
