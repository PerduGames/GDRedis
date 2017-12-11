/* register_types.cpp */

#include "error_macros.h"
#include "class_db.h"
#include "register_types.h"

#ifdef _WIN32
#include <Winsock2.h>
#endif /* _WIN32 */

#include "gdredis.h"

void register_gdredis_types() {
	ClassDB::register_class<GDRedis>();

	#ifdef _WIN32
      //! Windows netword DLL init
      WORD version = MAKEWORD(2, 2);
      WSADATA data;

      if (WSAStartup(version, &data) != 0) {
        std::cerr << "WSAStartup() failure" << std::endl;
      }
    #endif /* _WIN32 */

}

void unregister_gdredis_types() {
	#ifdef _WIN32
      WSACleanup();
    #endif /* _WIN32 */
}
