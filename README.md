# sHell - Simple Shell 0.1

A simple UNIX command interpreter making as a final project of the low-level programming and algorithm quarter at Holberton School.

## Description

This project is a simple UNIX command language interpreter that reads  and executes commands from either a file or standard input.

### Invocation

Usage: **sHell** [filename]

To invoke **sHell**, compile all `.c` files in the repository with the flag `-o sHell` and run the executable:

```
gcc *.c -o sHell
./sHell
```

**sHell** can be invoked both interactively and non-interactively.

**Interactive mode**: **sHell** is connected to a terminal and displays the prompt `$ ` when it is ready to read a command.

Example:
```
$./sHell
$
```

**Non interactive mode**
If **sHell** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'Holberton'" | ./sHell
'Holberton'
$
```

## Authors

* David Alzate Alzate <[Illker](https://github.com/illker)>
* Estephania Calvo Carvajal<[EstephaniaCalvoC](https://github.com/EstephaniaCalvoC)>