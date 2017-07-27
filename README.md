## vi-2048

Play vi-style 2048 in Linux and macOS console.

### Pic

#### menu
```
              ██╗   ██╗██╗██████╗  ██████╗ ██╗  ██╗ █████╗
              ██║   ██║██║╚════██╗██╔═████╗██║  ██║██╔══██╗
              ██║   ██║██║ █████╔╝██║██╔██║███████║╚█████╔╝
              ╚██╗ ██╔╝██║██╔═══╝ ████╔╝██║╚════██║██╔══██╗
               ╚████╔╝ ██║███████╗╚██████╔╝     ██║╚█████╔╝
                ╚═══╝  ╚═╝╚══════╝ ╚═════╝      ╚═╝ ╚════╝

                 h: left j:down k:up l:right tab:exit



                               RESUME
                                NEW
                            *   LOAD
                                SAVE
                                EXIT


```

#### game
```

################################################
##        ####        ####        ####        ##
##     2  ####        ####        ####        ##   SCORE:  0
##        ####        ####        ####        ##
################################################
################################################
##        ####        ####        ####        ##
##        ####        ####        ####        ##   HIGH:  0
##        ####        ####        ####        ##
################################################
################################################
##        ####        ####        ####        ##
##        ####        ####        ####        ##
##        ####        ####        ####        ##
################################################
################################################
##        ####        ####        ####        ##
##        ####        ####        ####        ##
##        ####        ####        ####        ##
################################################


```

### Install with Homebrew or Linuxbrew

```
brew tap xhinliang/tap
brew install vi2048
```

### Build && Install
**This Project is base on CMake 3.2, you have to install CMake first**

``` bash
git clone git@github.com:XhinLiang/vi2048.git
cd vi2048
cmake .
make
sudo make install
```

### Remove
``` bash
sudo rm /usr/local/bin/vi2048
rm /tmp/.vi2048_*
```

### License
```
MIT License

Copyright (c) 2016 XhinLiang

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
