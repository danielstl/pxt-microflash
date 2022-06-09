//% weight=5 color=#002050 icon="\uf0a0"
namespace filesystem {

    /*

    //-% blockId="open_path" block="file %filename"
    //-% weight=80
    export function open(path: string): FileHandle {
        const file = new FileHandle(path);
        file.open();

        return file;
    }

    //-% blockId="flush_file" block="flush %handle"
    export function flush(handle: FileHandle) {
        filesystem.fsFlush(handle.handle);
    }

    //-% blockId="close_file" block="close %handle"
    export function close(handle: FileHandle) {
        filesystem.fsClose(handle.handle);
    }

    //-% blockId="erase_file" block="delete %handle"
    export function erase(handle: FileHandle) {
        filesystem.remove(handle.path);
    }

    //-% blockId="seek_file" block="seek %handle to %position %seekType"
    export function seek(handle: FileHandle, position: number, seekType: SeekType) {
        filesystem.fsSeek(handle.handle, position, seekType);
    }

     */
/*
    export enum SeekType {
        //% block="from the current position"
        CurrentPosition = 0,
        //% block="from the start of the file"
        SetPosition = 1,
        //% block="from the end of the file"
        FileEndOffset = 2
    }

    export enum FileWriteOption {
        //% block="without a new line"
        None = 0,
        //% block="with a new line"
        NewLine = 1
    }

    //% blockId="files_create_handle" block="file %path"
    export function createHandle(path: string) {
        return new FileHandle(path);
    }

    //%
    export class FileHandle {

        path: string;
        handle: number;

        constructor(path: string) {
            this.path = path;
        }

        //% blockId="files_open" block="open %this"
        public open() {
            if (this.handle == -1) {
                this.handle = filesystem.fsOpen(this.path);
            }
        }

        //% blockId="files_flush" block="flush %this"
        public flush() {
            if (this.handle != -1) {
                filesystem.fsClose(this.handle);
            }
        }

        //% blockId="files_close" block="close %this"
        public close() {
            if (this.handle != -1) {
                filesystem.fsClose(this.handle);
            }
        }

        //% blockId="files_erase" block="delete %this"
        public erase() {
            filesystem.remove(this.path);
        }

        //% blockId="files_seek" block="seek %this to %position %seekType"
        public seek(position: number, seekType: SeekType) {
            filesystem.fsSeek(this.handle, position, seekType);
        }

        //% blockId="files_write_string" block="to %this write string %text %newline"
        //% text.shadowOptions.toString=true
        public writeText(text: string, newline: FileWriteOption) {
            filesystem.fsWriteString(this.handle, text + (newline == FileWriteOption.NewLine ? "\r\n" : ""));
        }

        //% blockId="files_read_all" block="read contents of %this"
        public readAll(): string {
            return filesystem.readFile(this.handle);
        }

        //% blockId="files_read_all_lines" block="read lines of %this"
        public readAllLines(): string[] {
            return filesystem.readFile(this.handle).split("\r\n");
        }
    }*/

    //%
    export enum FileOpenFlag {
        //% block="read"
        Read = 0x01,
        //% block="write"
        Write = 0x02,
        //% block="create"
        Create = 0x04
    }

    //% blockId="files_read_string" block="read string from %file"
    export function readString(path: string): string {
        const handle = filesystem.fsOpen(path, FileOpenFlag.Read);
        const buffer = filesystem.fsReadBuffer(handle, 4096);

        filesystem.fsClose(handle);

        return buffer.toString();
    }

    //% blockId="files_read_number" block="read number from %file"
    export function readNumber(path: string): number {
        return parseFloat(filesystem.readString(path));
    }

    //% blockId="files_read_lines" block="read lines of %file"
    export function readLines(path: string): string[] {
        return filesystem.readString(path).split("\r\n");
    }

    //% blockId="files_read_numbers" block="read lines of %file as numbers"
    export function readNumbers(path: string): number[] {
        return filesystem.readLines(path).map(line => parseFloat(line));
    }
}