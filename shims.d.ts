// Auto-generated. Do not edit.


    /**
     * Reading and writing to the filesystem.
     */
    //%
declare namespace filesystem {

    /**
     * Appends text and a new line to a file
     * @param filename file name, eg: "output.txt"
     * @param text the string to append to the end of the file
     */
    //% blockId="files_append_line" block="file %filename append line %text"
    //% blockExternalInputs=1 weight=90 blockGap=8
    //% text.shadowOptions.toString=true shim=filesystem::appendLine
    function appendLine(filename: string, text: string): void;

    /**
     * Appends text to a file
     * @param filename file name, eg: "output.txt"
     * @param text the string to append to the end of the file
     */
    //% blockId="fs_append_string" block="file %filename append string %text"
    //% blockExternalInputs=1 weight=86 blockGap=8
    //% text.shadowOptions.toString=true shim=filesystem::appendString
    function appendString(filename: string, text: string): void;

    /**
     * Reads the content of the file to send it to serial
     * @param filename file name, eg: "output.txt"
     */
    //% blockId="fs_write_to_serial" block="file %filename|read to serial"
    //% weight=80 shim=filesystem::readToSerial
    function readToSerial(filename: string): void;

    /**
     * Reads the contents of the file
     * @param filename file name, eg: "output.txt"
     */
    //% blockId="fs_read_file" block="read file %fd"
    //% weight=80 shim=filesystem::readFile
    function readFile(fd: int32): string;

    /**
     * Removes the file. There is no undo for this operation.
     * @param filename name of the file to remove, eg: "output.txt"
     */
    //% blockId="fs_remove" block="file remove %filename"
    //% weight=80 advanced=true blockGap=8 shim=filesystem::remove
    function remove(filename: string): void;

    /**
     * Creates a directory
     * @param name full qualified path to the new directory
     */
    //% advanced=true weight=10
    //% blockId=files_create_directory block="files create directory %name" shim=filesystem::createDirectory
    function createDirectory(name: string): void;

    /**
     *
     */
    //% blockId="fs_open" block="open file %path with flags %flags" shim=filesystem::fsOpen
    function fsOpen(path: string, flags: int32): int32;

    /**
     *
     */
    //% blockId="fs_flush" block="flush file handle %fd" shim=filesystem::fsFlush
    function fsFlush(fd: int32): int32;

    /**
     *
     */
    //% blockId="fs_close" block="close file handle %fd" shim=filesystem::fsClose
    function fsClose(fd: int32): int32;

    /**
     *
     */
    //% blockId="fs_seek" block="seek file %fd to offset %offset with flags %flags" shim=filesystem::fsSeek
    function fsSeek(fd: int32, offset: int32, flags: int32): int32;

    /**
     *
     */
    //% weight=0 advanced=true shim=filesystem::fsWriteString
    function fsWriteString(fd: int32, text: string): int32;

    /**
     *
     */
    //% blockId="fs_read_handle" block="read file handle %fd" shim=filesystem::fsRead
    function fsRead(fd: int32): int32;

    /**
     *
     */
    //% blockId="fs_write_buffer" block="write %fd %buffer" shim=filesystem::fsWriteBuffer
    function fsWriteBuffer(fd: int32, buffer: Buffer): int32;

    /**
     */
    //% blockId="fs_read_buffer" block="read %fd length %length" shim=filesystem::fsReadBuffer
    function fsReadBuffer(fd: int32, length: int32): Buffer;

    /**
     *
     */
    //% blockId="fs_test_dir" block="create test directory" shim=filesystem::test
    function test(): void;

    /**
     *
     */
    //% blockId="fs_format" block="format the filesystem" shim=filesystem::format
    function format(): void;
}

// Auto-generated. Do not edit. Really.
