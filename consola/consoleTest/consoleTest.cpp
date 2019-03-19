// consoleTest.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <cpp_redis/cpp_redis>
#include <cpp_redis/misc/macro.hpp>
#include <Winsock2.h>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <signal.h>
#include <string>
#include <tacopie/tacopie>

// #define ENABLE_SESSION = 1
using namespace std;


/*
// Example subscriber

std::condition_variable should_exit;

void
sigint_handler(int) {
  should_exit.notify_all();
}

int
main(void) {
#ifdef _WIN32
  //! Windows netword DLL init
  WORD version = MAKEWORD(2, 2);
  WSADATA data;

  if (WSAStartup(version, &data) != 0) {
    std::cerr << "WSAStartup() failure" << std::endl;
    return -1;
  }
#endif 

  //! Enable logging
  cpp_redis::active_logger = std::unique_ptr<cpp_redis::logger>(new cpp_redis::logger);

  cpp_redis::subscriber sub;


  sub.connect("127.0.0.1", 6379, [](const std::string& host, std::size_t port, cpp_redis::connect_state status) {
    if (status == cpp_redis::connect_state::dropped) {
      std::cout << "client disconnected from " << host << ":" << port << std::endl;
      should_exit.notify_all();
    }
  });

  //! authentication if server-server requires it
  // sub.auth("some_password", [](const cpp_redis::reply& reply) {
  //   if (reply.is_error()) { std::cerr << "Authentication failed: " << reply.as_string() << std::endl; }
  //   else {
  //     std::cout << "successful authentication" << std::endl;
  //   }
  // });

  sub.subscribe("some_chan", [](const std::string& chan, const std::string& msg) {
    std::cout << "MESSAGE " << chan << ": " << msg << std::endl;
  });
 
  sub.psubscribe("*", [](const std::string& chan, const std::string& msg) {
    std::cout << "PMESSAGE " << chan << ": " << msg << std::endl;
  });

  sub.commit();

  signal(SIGINT, &sigint_handler);
  std::mutex mtx;
  std::unique_lock<std::mutex> l(mtx);
  should_exit.wait(l);

#ifdef _WIN32
  WSACleanup();
#endif 

  return 0;
}
*/

/*
// test normal usage
int
main() {
#ifdef _WIN32
  //! Windows netword DLL init
  WORD version = MAKEWORD(2, 2);
  WSADATA data;

  if (WSAStartup(version, &data) != 0) {
    std::cerr << "WSAStartup() failure" << std::endl;
    return -1;
  }
#endif 

  //! Enable logging
  cpp_redis::active_logger = std::unique_ptr<cpp_redis::logger>(new cpp_redis::logger);

  cpp_redis::client client;

  client.connect("127.0.0.1", 6379,
    [](const std::string& host, std::size_t port, cpp_redis::connect_state status) {
      if (status == cpp_redis::connect_state::dropped) {
        std::cout << "client disconnected from " << host << ":" << port << std::endl;
      }
    });

  client.setnx("hello", "77", [](cpp_redis::reply& reply) {
	  if (reply.as_integer() == 1) {

		  cout << "New added" << endl;
	  }
      else {
            cout << "Already exists" << endl;
      }

  });


  auto replcmd = [](const cpp_redis::reply& reply) {
    std::cout << "set hello 42: " << reply << std::endl;
    // if (reply.is_string())
    //   do_something_with_string(reply.as_string())
  };

  const std::string group_name    = "groupone";
  const std::string session_name  = "sessone";
  const std::string consumer_name = "ABCD";

  std::multimap<std::string, std::string> ins;
  ins.insert(std::pair<std::string, std::string>{"message", "hello"});

#

  // same as client.send({ "SET", "hello", "42" }, ...)
  client.set("hello", "42", [](cpp_redis::reply& reply) {
    std::cout << "set hello 42: " << reply << std::endl;
    if (reply.ok()) {
      cout << reply.as_string() << endl;
    }
  });

  // same as client.send({ "DECRBY", "hello", 12 }, ...)
  client.decrby("hello", 12, [](cpp_redis::reply& reply) {
    std::cout << "decrby hello 12: " << reply << std::endl;
    // if (reply.is_integer())
    //   do_something_with_integer(reply.as_integer())
  });

  // same as client.send({ "GET", "hello" }, ...)
  client.get("hello", [](cpp_redis::reply& reply) {
    std::cout << "get hello: " << reply << std::endl;
    if (reply.is_string())
      for (int i = 0; i < 100; i++)
        cout << "Respuesta es :" << reply.as_string() << endl;
  });


  client.lpush("KAKA", {"Hola", "adios"}, [](cpp_redis::reply& reply) {
    if (reply.ok()) {

      if (reply.is_integer())
        cout << "Integer: " << reply.as_integer() << endl;
      else if (reply.is_string())
        cout << "string: " << reply.as_string() << endl;
    }
    else {

      cout << reply.error() << endl;
    }
  });


  // commands are pipelined and only sent when client.commit() is called
  // client.commit();

  // synchronous commit, no timeout
  client.sync_commit();

  // synchronous commit, timeout
  // client.sync_commit(std::chrono::milliseconds(100));

#ifdef _WIN32
  WSACleanup();
#endif 

  cout << "End!" << endl;
  return 0;
}
  */


// test normal usage 2 reconnection
int
main() {

  //! Windows netword DLL init
  WORD version = MAKEWORD(2, 2);
  WSADATA data;

  if (WSAStartup(version, &data) != 0) {
    std::cerr << "WSAStartup() failure" << std::endl;
    return -1;
  }


  //! Enable logging
  cpp_redis::active_logger = std::unique_ptr<cpp_redis::logger>(new cpp_redis::logger);
  cpp_redis::client client;

  client.connect("127.0.0.1", 6379,
    [&client](const std::string& host, std::size_t port, cpp_redis::connect_state status) {
      if (status == cpp_redis::connect_state::dropped) {
        std::cout << "client disconnected from " << host << ":" << port << std::endl;
      }
    });


  while (true) {

    try {
      client.set("hello", "42", [](cpp_redis::reply& reply) {
        std::cout << "set hello 42: " << reply << std::endl;
        if (reply.ok()) {
          cout << reply.as_string() << endl;
        }
      });

      client.sync_commit();
    }
    catch (exception& e) {
      cout << "Exception: " << e.what() << endl;

      try {

        client.connect("127.0.0.1", 6379,
          [&client](const std::string& host, std::size_t port, cpp_redis::connect_state status) {
            if (status == cpp_redis::connect_state::dropped) {
              std::cout << "client disconnected from " << host << ":" << port << std::endl;
            }
          });
    
	  }
	  catch (std::exception& j)
	  {
            cout << "Exceptio0n 2 : " << j.what() << endl;
	  }
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
  }


  // synchronous commit, timeout
  // client.sync_commit(std::chrono::milliseconds(100));

#ifdef _WIN32
  WSACleanup();
#endif

  cout << "End!" << endl;
  return 0;
}