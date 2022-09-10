// どのヘッダでも使うような機能はここに。
// 依存性が複雑になるので、なるべく追加しないこと。

#pragma once

#include <CRSLib/std_int.hpp>
#include <main.h>

namespace CRSLib::Can
{
	enum class CanX
	{
		single_can,
		can1,
		can2
	};

	inline constexpr u32 can_mtu = 8;
	inline constexpr u32 max_std_id = 0x07'FF;
	inline constexpr u32 max_ext_id = 0x03'FF'FF;
	inline constexpr u32 null_id = max_ext_id;

	enum class FifoIndex : u32
	{
		fifo0,
		fifo1
	};

	template<FifoIndex fifo_index>
	inline constexpr auto convert_fifo_index_to_hal_can_filter_fifo() noexcept
	{
		switch(fifo_index)
		{
		case FifoIndex::fifo0:
			return CAN_FilterFIFO0;
		case FifoIndex::fifo1:
			return CAN_FilterFIFO1;
		}
	}

	inline constexpr bool is_in_std_id_range(const u32 id) noexcept
	{
		return id <= max_std_id;
	}
}