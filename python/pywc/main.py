import argparse
from os.path import getsize


def count_bytes(filename: str) -> int:
    try:
        sz = getsize(filename)
        return sz
    except OSError:
        print("pywc: " + filename + ": No such file or directory")
        exit(1)


def count_lines(filename: str) -> int:
    with open(filename) as f:
        lines = 0
        for line in f:
            lines += 1
        return lines


def count_words(filename: str) -> int:
    with open(filename) as f:
        words = 0
        for line in f:
            words += len(line.split())
        return words


def count_chars(filename: str) -> int:
    with open(filename, encoding='utf-8', errors='replace') as f:
        char_count = 0
        for line in f:
            char_count += len(line)
        return char_count


def main():
    parser = argparse.ArgumentParser(
        prog='pywc',
        description='wc clone in Python')
    parser.add_argument("filename",
        type=str,
        help="the file on which to run the program")
    parser.add_argument('-c', '--count', action='store_true')
    parser.add_argument('-l', '--lines', action='store_true')
    parser.add_argument('-w', '--words', action='store_true')
    parser.add_argument('-m', '--chars', action='store_true')
    
    args = parser.parse_args()
    if args.count:
        print(count_bytes(args.filename), end=' ')
    if args.lines:
        print(count_lines(args.filename), end=' ')
    if args.words:
        print(count_words(args.filename), end=' ')
    if args.chars:
        print(count_chars(args.filename), end=' ')
    
    if len(args) == 1:
        print(count_bytes(args.filename), end=' ')
        print(count_lines(args.filename), end=' ')
        print(count_words(args.filename), end=' ')

    
    print(args.filename)


if __name__ == '__main__':
    main()