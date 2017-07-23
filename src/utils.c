#include "utils.h"
#include <unistd.h>
#include <pwd.h>

char *get_home_path() {
    struct passwd *pw = getpwuid(getuid());
    char *home_dir = pw->pw_dir;
    return home_dir;
}
