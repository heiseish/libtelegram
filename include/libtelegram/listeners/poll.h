#pragma once

#ifndef TELEGRAM_LISTENERS_POLL_H_INCLUDED
#define TELEGRAM_LISTENERS_POLL_H_INCLUDED

#include "libtelegram/config.h"

#include <signal.h>
#include <urdl/istream.hpp>
#include <boost/asio.hpp>
#include "base.h"
#include "libtelegram/sender.h"

void signal_handler(int s);

namespace telegram {

class sender;

namespace listener {

class poll : public base<poll> {
  telegram::sender &sender;
  static bool signal_handler_is_set;                                            // track the state of the signal handler
  std::atomic_flag keep_running;                                                // used to stop the poll externally from other threads
  static std::atomic_flag keep_running_global;                                  // used by the signal handler to terminate the poll loop, and can be modified externally

public:
  static unsigned int constexpr const poll_timeout_default = 60 * 60;           // default poll timeout in seconds
  unsigned int poll_timeout = poll_timeout_default;

  // TODO: statistics on number of times polled etc
  // TODO: statistics on requests serviced per thread etc

  poll(telegram::sender &sender, unsigned int poll_timeout = poll_timeout_default);

  void run();
  void stop();
  static void stop_all();

  static void set_signal_handler();
  static void unset_signal_handler();
  static bool is_signal_handler_set();
};

template<typename T>
std::string_view constexpr plural(T value) {
  /// Helper function to provide a pluralising "s" suffix to words if a number is plural
  return (value == 1 ? "" : "s");
}


}
}

#endif // TELEGRAM_LISTENERS_POLL_H_INCLUDED
