/*
 * \brief  Lx_emul udelay function for very short delays
 * \author Stefan Kalkowski
 * \date   2021-07-10
 */

/*
 * Copyright (C) 2021 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

#include <base/log.h>
#include <lx_kit/env.h>
#include <time.h>


void lx_emul_time_udelay(unsigned long usec)
{
	if (usec > 100)
		Genode::error("Cannot delay that long ", usec, " microseconds");

	auto curr_usec = [&]
	{
		return Lx_kit::env().timer.curr_time().trunc_to_plain_us().value;
	};

	unsigned long const start = curr_usec();
	while (curr_usec() < start + usec) { }
}
