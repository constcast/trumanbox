#ifndef _HELPER_FILE_H_
#define _HELPER_FILE_H_

#include "definitions.h"

void create_tmp_folders();
void change_to_tmp_folder();
int create_index_file();
int create_path_tree(char *path, int user_id, int group_id);
void build_tree(const connection_t *conn, char *cmd_str);

#endif
