
#ifndef HAZELCAST_API_H
#define HAZELCAST_API_H

#ifdef HAZELCAST_USE_STATIC
#  define HAZELCAST_API
#  define HAZELCAST_PRIVATE
#else
#  ifndef HAZELCAST_API
#    ifdef HAZELCAST_EXPORTS
        /* We are building this library */
#      define HAZELCAST_API 
#    else
        /* We are using this library */
#      define HAZELCAST_API 
#    endif
#  endif

#  ifndef HAZELCAST_PRIVATE
#    define HAZELCAST_PRIVATE 
#  endif
#endif

#ifndef HAZELCAST_DEPRECATED
#  define HAZELCAST_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef HAZELCAST_DEPRECATED_EXPORT
#  define HAZELCAST_DEPRECATED_EXPORT HAZELCAST_API HAZELCAST_DEPRECATED
#endif

#ifndef HAZELCAST_DEPRECATED_NO_EXPORT
#  define HAZELCAST_DEPRECATED_NO_EXPORT HAZELCAST_PRIVATE HAZELCAST_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef HAZELCAST_NO_DEPRECATED
#    define HAZELCAST_NO_DEPRECATED
#  endif
#endif

#endif /* HAZELCAST_API_H */
