#pragma once

#include <functional>

using Runnable = std::function<void()>;

template<typename T> using Consumer = std::function<void(const T&)>;

namespace Noop {

  inline void runnable() {
    /* do nothing */
  };

  template<typename T> void consumer(const T& value) {
    /* do nothing */
  };
}
