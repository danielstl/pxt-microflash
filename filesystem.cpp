#include "pxt.h"

#if MICROBIT_CODAL
#include "CodalFS.h"
#endif

/**
 * Reading and writing to the filesystem.
 */
//%
namespace filesystem {

// Initializes file system. Must be called before any FS operation.
// built-in size computation for file system
// does not take into account size changes
// for compiled code
    int initFileSystem()
    {
    #if MICROBIT_CODAL
        uBit.filesystem.init();
    #endif
    return 1;
    }

/**
    * Appends text and a new line to a file
    * @param filename file name, eg: "output.txt"
    * @param text the string to append to the end of the file
    */
//% blockId="files_append_line" block="append %text to file %filename"
//% blockExternalInputs=1 weight=90 blockGap=8
//% text.shadowOptions.toString=true
    void appendLine(String text, String filename)
    {
    #if MICROBIT_CODAL
        initFileSystem();

        auto fd = uBit.filesystem.open(MSTR(filename).toCharArray(), FS_CREAT | FS_APPEND | FS_WRITE);
        uBit.filesystem.write(fd, (uint8_t *) MSTR(text).toCharArray(), MSTR(text).length());
        uBit.filesystem.write(fd, (uint8_t *) "\r\n", 2);
        uBit.filesystem.close(fd);
        #endif
    }

/**
    * Appends text to a file
    * @param filename file name, eg: "output.txt"
    * @param text the string to append to the end of the file
    */
//% blockId="fs_append_string" block="append %text to file %filename with newline"
//% blockExternalInputs=1 weight=86 blockGap=8
//% text.shadowOptions.toString=true
    void appendString(String text, String filename)
    {
    #if MICROBIT_CODAL
        initFileSystem();

        auto fd = uBit.filesystem.open(MSTR(filename).toCharArray(), FS_CREAT | FS_APPEND | FS_WRITE);
        uBit.filesystem.write(fd, (uint8_t *) MSTR(text).toCharArray(), MSTR(text).length());
        uBit.filesystem.close(fd);
        #endif
    }

/**
* Reads the content of the file to send it to serial
* @param filename file name, eg: "output.txt"
*/
//% blockId="fs_write_to_serial" block="read file %filename to serial"
//% weight=80
    void readToSerial(String filename) {
    #if MICROBIT_CODAL
        initFileSystem();

        auto fd = uBit.filesystem.open(MSTR(filename).toCharArray(), FS_READ);

        char buf[32];

        int read = 0;
        while((read = uBit.filesystem.read(fd, (uint8_t *) buf, sizeof(buf))) > 0) {
            uBit.serial.send((uint8_t*)buf, read * sizeof(char), SYNC_SPINWAIT);
        }

        uBit.filesystem.close(fd);
        #endif
    }

    /**
    * Reads the contents of the file
    * @param filename file name, eg: "output.txt"
    */
    //% blockId="fs_read_file" block="read file %fd"
    //% weight=80 advanced=true
        String readFile(int fd) {
        #if MICROBIT_CODAL
            initFileSystem();

            char buf[128];

            int read = 0;
            while((read = uBit.filesystem.read(fd, (uint8_t *) buf, sizeof(buf))) > 0) {

            }

            uBit.filesystem.close(fd);

            return mkString(buf, sizeof(buf));
            #endif
        }

/**
    * Removes the file. There is no undo for this operation.
    * @param filename name of the file to remove, eg: "output.txt"
    */
//% blockId="fs_remove" block="delete file %filename"
//% weight=80 blockGap=8
    void remove(String filename)
    {
    #if MICROBIT_CODAL
        initFileSystem();
        uBit.filesystem.remove(MSTR(filename).toCharArray());
        #endif
    }

/**
* Creates a directory
* @param name full qualified path to the new directory
*/
//% weight=10
//% blockId=files_create_directory block="create directory %name"
    void createDirectory(String name) {
    #if MICROBIT_CODAL
        initFileSystem();
        uBit.filesystem.createDirectory(MSTR(name).toCharArray());
        #endif
    }

/**
*
*/
//% blockId="fs_open" block="open file %path with flags %flags"
    int fsOpen(String path, int flags) {
    #if MICROBIT_CODAL
        initFileSystem();
        return uBit.filesystem.open(MSTR(path).toCharArray(), flags);
        #endif
    }

/**
*
*/
//% blockId="fs_flush" block="flush file handle %fd" advanced=true
    int fsFlush(int fd) {
    #if MICROBIT_CODAL
        if (fd < 0) return MICROBIT_NOT_SUPPORTED;

        initFileSystem();
        return uBit.filesystem.flush(fd);
        #endif
    }

/**
*
*/
//% blockId="fs_close" block="close file handle %fd" advanced=true
    int fsClose(int fd) {
    #if MICROBIT_CODAL
        if (fd < 0) return MICROBIT_NOT_SUPPORTED;

        initFileSystem();
        return uBit.filesystem.close(fd);
        #endif
    }

/**
*
*/
//% blockId="fs_seek" block="seek file %fd to offset %offset with flags %flags" advanced=true
    int fsSeek(int fd, int offset, int flags) {
    #if MICROBIT_CODAL
        if (fd < 0) return MICROBIT_NOT_SUPPORTED;
        if (offset < 0) return MICROBIT_INVALID_PARAMETER;

        initFileSystem();
        return uBit.filesystem.seek(fd, offset, flags);
        #endif
    }

/**
*
*/
//% weight=0 advanced=true
    int fsWriteString(int fd, String text) {
    #if MICROBIT_CODAL
        if (fd < 0) return MICROBIT_NOT_SUPPORTED;

        initFileSystem();

        return uBit.filesystem.write(fd, (uint8_t *) MSTR(text).toCharArray(), MSTR(text).length());
        #endif
    }

/**
*
*/
//% blockId="fs_read_handle" block="read file handle %fd" advanced=true
    int fsRead(int fd) {
    #if MICROBIT_CODAL
        if (fd < 0) return MICROBIT_NOT_SUPPORTED;
        initFileSystem();

        char c[1];
        int ret = uBit.filesystem.read(fd, (uint8_t*)&c, 1);
        if (ret != 1) return ret;
        else return c[0];
        #endif
    }

    /**
    *
    */
    //% blockId="fs_write_buffer" block="write %fd %buffer" advanced=true
    int fsWriteBuffer(int fd, Buffer buffer) {
    #if MICROBIT_CODAL
        if (fd < 0) return MICROBIT_NOT_SUPPORTED;

        initFileSystem();
        return uBit.filesystem.write(fd, buffer->data, buffer->length);
        #endif
    }

    /**
    */
    //% blockId="fs_read_buffer" block="read %fd length %length" advanced=true
    Buffer fsReadBuffer(int fd, int length) {
    #if MICROBIT_CODAL
        if (fd < 0 || length < 0)
            return mkBuffer(NULL, 0);

        initFileSystem();
        Buffer buf = mkBuffer(NULL, length);

        int ret = uBit.filesystem.read(fd, buf->data, buf->length);

        if (ret < 0) return mkBuffer(NULL, 0);
        else if (ret != length) {
            auto sbuf = mkBuffer(buf->data, ret);
            decrRC(buf);
            return sbuf;
        }
        else return buf;
        #endif
    }

    /**
    *
    */
    //% blockId="fs_test_dir" block="create test directories" advanced=true
        void test() {
        #if MICROBIT_CODAL

            initFileSystem();

            uBit.filesystem.createDirectory("makecode-test");
            uBit.filesystem.createDirectory("makecode-test/nested-test");
            uBit.filesystem.createDirectory("makecode-test2");
            uBit.filesystem.createDirectory("makecode-test3");
            uBit.filesystem.createDirectory("makecode-test4");
            #endif
        }

        /**
        *
        */
        //% blockId="fs_format" block="format the filesystem"
            void format() {
            #if MICROBIT_CODAL

                initFileSystem();

                uBit.filesystem.format();
                #endif
            }

}
