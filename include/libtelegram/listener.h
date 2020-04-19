#pragma once


#ifndef TELEGRAM_LISTENER_H_INCLUDED
#define TELEGRAM_LISTENER_H_INCLUDED

#ifndef TELEGRAM_NO_LISTENER_FCGI
  #include "listeners/fcgi.h"
#endif // TELEGRAM_NO_LISTENER_FCGI
#ifndef TELEGRAM_NO_LISTENER_POLL
  #include "listeners/poll.h"
#endif // TELEGRAM_NO_LISTENER_POLL

#endif // TELEGRAM_LISTENER_H_INCLUDED
