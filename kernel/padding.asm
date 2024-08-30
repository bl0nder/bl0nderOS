;EXTREMELY IMPORTANT: QEMU dies NOT run images < 3KB in size as hard disks 
;So, there are 2 options:
;   1. Run image as floppy disk using -fda flags
;   2. Append image with 3 additional sectors to bring it up to 3KB and then run as hard disk (-hda)
;   Source for point 2 (https://stackoverflow.com/questions/28564676/unable-to-read-from-disk-in-qemu)
padding:
    times 256 dw 0xface
    times 256 dw 0x1234
    times 256 dw 0xaaaa