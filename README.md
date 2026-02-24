# Spell Checker (C++)

This project implements a spell checker in C++ that reads a dictionary file and analyzes text files to detect misspelled words. It compares each word in the input text against a list of valid words and reports any words that are not found in the dictionary.

This project demonstrates core software engineering skills including file handling, string processing, compilation using a Makefile, and command-line execution.

---

## Overview

The spell checker works by loading a dictionary file containing valid words and then analyzing one or more input text files. Each word in the input file is compared against the dictionary. Words not found in the dictionary are identified as spelling errors.

This simulates the basic functionality of real-world spell checking systems used in text editors and software applications.

---

## Project Structure


spellchecker/
│
│── spellchecker.cpp # Main source code
│── Makefile # Compilation instructions
│── words.txt # Dictionary file containing valid words
│
│── alice.txt # Example input file
│── frankenstein.txt # Example input file
│── bicycle.txt # Example input file
│── tooinkle.txt # Example input file
│
└── README.md # Project documentation


---

## Dictionary File

The dictionary file:


words.txt


contains a list of valid words. Each word in this file is considered correctly spelled.

The spell checker uses this file as the reference to verify spelling.

You can modify this file or replace it with your own custom dictionary.

---

## Input Text Files

Example text files included in the project:


alice.txt
frankenstein.txt
bicycle.txt
tooinkle.txt


These files are used to test the spell checker. The program reads each file and compares its words against the dictionary.

You can also create your own `.txt` files and test them with the program.

---

## Compilation Instructions

This project uses a Makefile to simplify compilation.

Open a terminal in the project directory and run:


make


This command will compile the source code and generate the executable file:


spellchecker


---

## Execution Instructions

After compiling, run the program using the following syntax:


./spellchecker words.txt inputfile.txt


Where:

- `words.txt` is the dictionary file
- `inputfile.txt` is the text file you want to analyze

---

## Example Executions


./spellchecker words.txt alice.txt

./spellchecker words.txt frankenstein.txt

./spellchecker words.txt bicycle.txt

./spellchecker words.txt tooinkle.txt


---

## Example Workflow


make
./spellchecker words.txt alice.txt


The program will analyze the file and report spelling results.

---

## Concepts Demonstrated

This project demonstrates the following programming and software engineering concepts:

- File input and output
- String processing
- Dictionary-based lookup
- Command-line arguments
- Compilation using Makefile
- C++ program structure
- Software organization

---

## Technologies Used

- C++
- Makefile
- Standard C++ Library
- Command-line interface

---

## Author

Luis Alejandro Olvera Hernández

---

## Purpose

This project was developed for educational purposes to strengthen skills in C++ programming, file handling, and software compilation using Makefiles. It demonstrates practical implementation of text processing and algorithmic problem solving.
