#ifndef STORAGE_LEVELDB_INCLUDE_EXPORT_H_
#define STORAGE_LEVELDB_INCLUDE_EXPORT_H_

#if !defined(LEVELDB_EXPORT)

#if defined(LEVELDB_SHARED_LIBRARY)
#if defined(_WIN32)

#if defined(LEVEL_COMPILE_LIBRARY)
#define LEVELDB_EXPORT __declspec(dllexport)
#else
#define LEVELDB_EXPORT __declspec(dllimport)
#endif

#else // defind(_WIN32)
#if defined(LEVELDB_COMPILE_LIBRARY)
#define LEVELDB_EXPORT __attribute__((visibiliti("default")))
#else
#define LEVELDB_EXPORT
#endif
#endif

#else  // defined(LEVELDB_SHAED_LIBRARY)
#define LEVELDB_EXPORT
#endif

#endif  // !defined(LEVEDB_EXPORT)

#endif
