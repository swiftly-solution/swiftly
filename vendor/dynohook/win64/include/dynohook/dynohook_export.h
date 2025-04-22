
#ifndef DYNO_API_H
#define DYNO_API_H

#ifdef DYNO_STATIC
#  define DYNO_API
#  define DYNO_PRIVATE
#else
#  ifndef DYNO_API
#    ifdef dynohook_EXPORTS
        /* We are building this library */
#      define DYNO_API 
#    else
        /* We are using this library */
#      define DYNO_API 
#    endif
#  endif

#  ifndef DYNO_PRIVATE
#    define DYNO_PRIVATE 
#  endif
#endif

#ifndef DYNO_DEPRECATED
#  define DYNO_DEPRECATED __declspec(deprecated)
#endif

#ifndef DYNO_DEPRECATED_EXPORT
#  define DYNO_DEPRECATED_EXPORT DYNO_API DYNO_DEPRECATED
#endif

#ifndef DYNO_DEPRECATED_NO_EXPORT
#  define DYNO_DEPRECATED_NO_EXPORT DYNO_PRIVATE DYNO_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef DYNO_NO_DEPRECATED
#    define DYNO_NO_DEPRECATED
#  endif
#endif

#endif /* DYNO_API_H */
