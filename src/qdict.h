/*
 * See Copyright Notice in qnode.h
 */

#ifndef __QDICT_H__
#define __QDICT_H__

#include "qlist.h"
#include "qstring.h"

enum {
  QDICT_KEY_NUMBER = 0,
  QDICT_KEY_STRING = 1,
};

typedef struct qkey_t {
  union {
    int num;
    const char *str;
  } data;

  unsigned short type;
} qkey_t;

#define QKEY_NUM(num) {{(num)}, QDICT_KEY_NUMBER}
#define QKEY_STR(str) {{(str)}, QDICT_KEY_STRING}

enum {
  QDICT_VAL_NUMBER = 0,
  QDICT_VAL_STRING = 1,
  QDICT_VAL_USERDATA = 2,
};

typedef struct qdict_key_t {
  union {
    int num;
    qstring_t *str;
  } data;

  unsigned short type;
} qdict_key_t;

typedef struct qdict_val_t {
  union {
    int num;
    qstring_t *str;
    void *ptr;
  } data;
  unsigned short type;
} qdict_val_t;

typedef struct qdict_entry_t {
  qlist_t entry;
  qdict_key_t key;
  qdict_val_t val;
} qdict_entry_t;

typedef struct qdict_t {
  qlist_t **buckets;
  unsigned int hashsize;
} qdict_t;

qdict_t* qdict_new(unsigned int hashsize);
int qdict_add(qdict_t *dict, qkey_t *key, qdict_val_t *val);
int qdict_replace(qdict_t *dict, qkey_t *key, qdict_val_t *val);
qdict_val_t* qdict_get(qdict_t *dict, qkey_t *key);

#endif  /* __QDICT_H__ */