#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
char*
fmtname(char *path)
{
  static char buf[DIRSIZ+1];
  char *p;

  // Find first character after last slash.
  for(p=path+strlen(path); p >= path && *p != '/'; p--)
    ;
  p++;

  // Return blank-padded name.
  if(strlen(p) >= DIRSIZ)
    return p;
  memmove(buf, p, strlen(p));
  memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
  return buf;
}

void
find(char *directory, char* filename)
{
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;

  if((fd = open(directory, 0)) < 0){
    fprintf(2, "ls: cannot open %s\n", directory);
    return;
  }

  if(fstat(fd, &st) < 0){
    fprintf(2, "ls: cannot stat %s\n", directory);
    close(fd);
    return;
  }

  switch(st.type){
  case T_DEVICE:
  case T_FILE:
	if(strcmp(directory, filename) == 0) {
		printf("%s %d %d %l\n", fmtname(directory), st.type, st.ino, st.size);
	}
    break;

  case T_DIR:
    if(strlen(directory) + 1 + DIRSIZ + 1 > sizeof buf){
      printf("ls: path too long\n");
      break;
    }
    strcpy(buf, directory);
    p = buf+strlen(buf);
    *p++ = '/';
    while(read(fd, &de, sizeof(de)) == sizeof(de)){
      if(de.inum == 0)
        continue;
      memmove(p, de.name, DIRSIZ);
      p[DIRSIZ] = 0;
      if(stat(buf, &st) < 0){
        printf("ls: cannot stat %s\n", buf);
        continue;
      }
	  char *name = fmtname(buf); 
	  char *temp = strtrim(name);
	  char *temp2 = strtrim(buf);
	  if(strcmp(filename, temp) == 0){
		  char *temp2 = strtrim(buf);
		  printf("%s\n", temp2);
	  }
	  if(st.type == T_DIR){
		if(strcmp(temp, ".") != 0 && strcmp(temp, "..") != 0) {
			find(temp2, filename);
		}
	  }
    }
    break;
  }
  close(fd);
}

int
main(int argc, char *argv[])
{
  if(argc < 2){
	  fprintf(2, "Wrong number of arguments\n");
    exit(0);
  }
  if(argc == 3) {
	char *dir = argv[1];
	char *file = argv[2];
	find(dir, file);
	exit(0);
  } else {
	fprintf(2, "Wrong number of arguments\n");
	exit(0);
  }
  exit(0);
}
