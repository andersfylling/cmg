#pragma once

#include <string_view>

namespace cmg {
namespace utils {

constexpr uint_fast8_t LSB(const uint_fast64_t board)
{
#ifdef __linux__
  return (board > 0) ? __builtin_ffsl(board) - 1 : 0;
#else
  for (int i = 0; i < 64; i++) {
    if (isset(board, i)) {
      return i;
    }
  }
#endif
}

constexpr uint_fast8_t MSB(const uint64_t board)
{
#ifdef __linux__
  return (board > 0) ? 63 - __builtin_clzll(board) : 0;
#else
  for (int i = 63; i >= 0; i--) {
    if (isset(board, i)) {
      return i;
    }
  }
#endif
}

constexpr uint_fast8_t NLSB(uint64_t& board, const uint8_t index)
{
  board &= ~(1ull << index);
  return LSB(board);
}

constexpr uint_fast8_t NMSB(uint64_t& board, const uint8_t index)
{
  board &= ~(1ull << index);
  return MSB(board);
}

constexpr bool isset(const uint_fast64_t board, const uint_fast8_t index)
{
  return (board & (1ull << index)) != 0;
}

constexpr uint64_t indexToBitboard (const uint8_t index) {
  return 1ull << index;
}

} // utils
} // movegencpp