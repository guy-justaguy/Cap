# Cap-Alpha

*Cap-Alpha*

_----Non Unix based kernel----_

#*_if you want to compile please follow these instructions:_*#
1. you have to be on Linux to use these commands. 
2. Install _`clang`_ if not available. 
3. Install _`make`_ if not available.
4. Install _`ld`_ if not available.
5. Download the source code.
6. Run
       _`mkdir -p kernel`_
(in any dir)
9. Now extract the source code inside the new dir. Or run this command:
       _`unzip <name_of_source_code_file.zip>  /kernel`_
11. Now _`cd`_ into the _`/kernel`_ dir.
12. Now run
      _`make`_
14. A file named _`kernel.elf`_ will appear in the dir.
15. Now run
      _`mkdir -p iso_root`_
17. _`cp`_ the 'kernel.elf' file into iso_root.
18. Go back to the _`/kernel`_ dir.
19. Now run
    _`grub2-mkrescue iso_root -o kernel.iso`_
21. An ISO file called _`kernel.iso`_ should appear.
22. Use QEMU OVMF to boot this ISO.
 If you encounter any problems during compilation process, please contact _<tungsahuur1234@gmail.com>_

    you want, you can use the build.sh by using
     _`chmod +x build.sh && ./build.sh`_
Also, there is a pre-built image in the releases.
