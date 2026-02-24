#include "utils.h"
#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>

char *get_home_path() {
    struct passwd *pw = getpwuid(getuid());
    if (pw && pw->pw_dir) {
        return pw->pw_dir;
    }
    return getenv("HOME");
}
