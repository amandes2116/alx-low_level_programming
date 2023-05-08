#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *entr_ident);
void print_magic(unsigned char *entr_ident);
void print_class(unsigned char *entr_ident);
void print_data(unsigned char *entr_ident);
void print_version(unsigned char *entr_ident);
void print_abi(unsigned char *entr_ident);
void print_osabi(unsigned char *entr_ident);
void print_type(unsigned int ent_type, unsigned char *entr_ident);
void print_entry(unsigned long int entry_point, unsigned char *entr_ident);
void close_elf(int el);
/**
*check_elf - To Check if File is ELF File.
*@ident:The Pointer an Array Containing The ELF Magic Number.
*
*Description:The File If  is Not ELF File - Exit Code is 98.
*/
void check_elf(unsigned char *entr_ident)
{
int index;
for (index = 0; index < 4; index++)
{
if (entr_ident[index] != 127 &&
entr_ident[index] != 'E' &&
entr_ident[index] != 'L' &&
entr_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}
/**
*print_magic - To Print Magic Number Of ELF Header.
*@ident: The Pointer an Array Containing ELF Magic Number.
*
*Description: The Magic Number Separated By Spaces.
*/
void print_magic(unsigned char *entr_ident)
{
int index;
printf(" Magic: ");
for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", entr_ident[index]);
if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}
/**
* print_class - To Print Class of ELF Header.
* @ident: The Pointer an Array Containing ELF Class.
*/
void print_class(unsigned char *entr_ident)
{
printf(" Class: ");
switch (entr_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", entr_ident[EI_CLASS]);
}
}
/**
*print_data - To Print Of The Data of ELF Header.
*@ident: The Pointer an Array Containing ELF Class.
*/
void print_data(unsigned char *entr_ident)
{
printf(" Data: ");
switch (entr_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", entr_ident[EI_CLASS]);
}
}
/**
* print_version - To Print Of The Version Of ELF Header.
* @ident: The Pointer an Array containe ELF Version.
*/
void print_version(unsigned char *entr_ident)
{
printf(" Version: %d",
entr_ident[EI_VERSION]);
switch (entr_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}
/**
* print_osabi - The Print Of OS/ABI an ELF Header.
* @entr_ident:Pointer an Array Containe ELF Version.
*/
void print_osabi(unsigned char *entr_ident)
{
printf(" OS/ABI: ");
switch (entr_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", entr_ident[EI_OSABI]);
}
}
/**
*print_abi - To Print ABI Version Of an ELF Header.
*@entr_ident: The Pointer an Array Containe ELF ABI Version.
*/
void print_abi(unsigned char *entr_ident)
{
printf(" ABI Version: %d\n",
entr_ident[EI_ABIVERSION]);
}
/**
* print_type - Print Type Of an ELF Header.
* @ent_type: ELF Type.
* @entr_ident: The Pointer an Array Containing ELF Class.
*/
void print_type(unsigned int ent_type, unsigned char *entr_ident)
{
if (entr_ident[EI_DATA] == ELFDATA2MSB)
ent_type >>= 8;
printf(" Type: ");
switch (ent_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", ent_type);
}
}
/**
* print_entry - Print Entry Point Of ELF Header.
* @entry_point: Address Of The ELF Entry Point.
* @entr_ident_: The Pointer an Array Containe The ELF Class.
*/
void print_entry(unsigned long int entry_point, unsigned char *entr_ident)
{
printf(" Entry point address: ");
if (entr_ident[EI_DATA] == ELFDATA2MSB)
{
entry_point = ((entry_point << 8) & 0xFF00FF00) |
((entry_point >> 8) & 0xFF00FF);
entry_point = (entry_point << 16) | (entry_point >> 16);
}
if (entr_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)entry_point);
else
printf("%#lx\n", entry_point);
}
/**
*close_elf - Close ELF File.
*@el: a File Descriptor Of The ELF File.
*
*Description:The File If Can't Close - Exit Code is 98.
*/
void close_elf(int el)
{
if (close(el) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd %d\n", el);
exit(98);
}
}
/**
* main - Display Information Containe in The
* ELF Header  Start Of an ELF File.
* @arc: Number Of Argument Supplied To  Program.
* @arv: The Array Of Pointer The Argument.
*
* Return:Success.
*
* Description:The Tile If Is Not ELF File Or
* If The Functiona Fail - Exit Code is 98.
*/
int main(int __attribute__((__unused__)) arc, char *arv[])
{
Elf64_Ehdr *header;
int o, r;
o = open(arv[1], O_RDONLY);
if (o == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", arv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_elf(o);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", arv[1]);
exit(98);
}
r = read(o, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
close_elf(o);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", arv[1]);
exit(98);
}
check_elf(header->entr_ident);
printf("ELF Header:\n");
print_magic(header->entr_ident);
print_class(header->entr_ident);
print_data(header->entr_ident);
print_version(header->entr_ident);
print_osabi(header->entr_ident);
print_abi(header->entr_ident);
print_type(header->ent_type, header->entr_ident);
print_entry(header->entry_point, header->entr_ident);
free(header);
close_elf(o);
return (0);
}
