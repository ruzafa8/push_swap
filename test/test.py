#!/usr/bin/env python3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 15:14:35 by jmorillo          #+#    #+#              #
#    Updated: 2022/08/19 15:53:16 by jmorillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import itertools
import math
import os
import random
import re
import subprocess
import sys

RED = '\033[31m'
GREEN = '\033[32m'
YELLOW = '\033[33m'
BLUE = '\033[1;34m'
MAGENTA = '\033[1;35m'
CYAN = '\033[1;36m'
RESET = '\033[0m'

PUSH_SWAP = '../push_swap'

if os.uname().sysname == 'Darwin':
    CHECKER = './checker_Mac'
elif os.uname().sysname == 'Linux':
    CHECKER = './checker_linux'
else:
    print(f'No existe "checker" para {os.uname().sysname}')
    exit()

TESTS=[
[],
[''],
[' '],
['-'],
['42',],
['-42'],
['+42'],
['-+42'],
['--42'],
['-42-'],
['-42A'],
['A'],
['1', '', '2'],
['FOOBAR'],
['2147483647'],
['2147483648'],
['-2147483648'],
['-12345678901234567890123456789'],
['12345678901234567890123456789'],
['3', '2', '6 5 4', '1'],
['3', '2', '6 5 A', '1'],
['2', '3', '5', '7', '11', '13', '17', '19']
]

def sort_numbers(numbers, check=True):
    ps_command = [PUSH_SWAP] + numbers
    ps_response = b''
    error = False
    try:
        ps_response = subprocess.check_output(ps_command, stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as ex:
        if (ex.output.decode().strip() == 'Error'):
            error = True
        else:
            print(f'  Error en push_swap: "{ex.output.decode().strip()}" (code={ex.returncode})')
            exit(1)
    steps = ps_response.decode().strip()
    step_count = len(steps.splitlines())
    if check:
        check_command = [CHECKER] + numbers
        try:
            p = subprocess.Popen(check_command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
            stdout_data = p.communicate(input=ps_response)[0]
        except subprocess.CalledProcessError as ex:
            print(f'  Error en checker: {ex.returncode}')
        check_result = stdout_data.decode().strip()
    else:
        check_result = ""
    return step_count, error, check_result

def complex_message(length, moves):
    complex = math.ceil(math.log(length, 2) * length)
    return f'{YELLOW}< {complex}{RESET}'

def points_message(points):
    return f'{YELLOW}{points} punto{"" if points == 1 else "s"}{RESET}'

def points_3(moves):
    if moves <= 3:
        return 1
    else:
        return 0

def points_5(moves):
    if moves <= 12:
        return 1
    else:
        return 0

def points_100(moves):
    if moves < 700:
        return 5
    if moves < 900:
        return 4
    if moves < 1100:
        return 3
    if moves < 1300:
        return 2
    if moves < 1500:
        return 1
    else:
        return 0

def points_500(moves):
    if moves < 5500:
        return 5
    if moves < 7000:
        return 4
    if moves < 8500:
        return 3
    if moves < 10000:
        return 2
    if moves < 11500:
        return 1
    else:
        return 0

def calc_comb_numbers(length):
    numbers = [str(n) for n in range(1, length + 1)]
    result = [list(n) for n in itertools.permutations(numbers)]
    return result

def sort_comb_numbers(length):
    randoms = calc_comb_numbers(length)
    total_moves = 0
    min_moves = sys.maxsize
    max_moves = 0
    for numbers in randoms:
        moves, error, check = sort_numbers(numbers)
        if error or check != 'OK':
            total_moves = 0
            min_moves = -1
            max_moves = -1
            break
        total_moves += moves
        if moves > max_moves:
            max_moves = moves
        if moves < min_moves:
            min_moves = moves
    mean_moves = total_moves / len(randoms)
    return mean_moves, min_moves, max_moves

def print_all_comb_numbers(length):
    randoms = calc_comb_numbers(length)
    for numbers in randoms:
        moves, error, check = sort_numbers(numbers)
        if check == 'OK' or (check == 'Error' and error) or (check == '' and not error and not moves):
            check = f'[{GREEN}OK{RESET}]'
        elif check == 'KO':
            check = f'[{RED}KO{RESET}]'
        moves = f'{MAGENTA}{moves}{RESET}' if not error else f'{CYAN}Error{RESET}'
        numbers = [f'{BLUE}{n}{RESET}' for n in numbers]
        print(f'combination({", ".join(numbers)}) --> {moves} {check}')

def calc_random_numbers(length, count):
    numbers = [str(n) for n in range(1, length + 1)]
    result = list()
    #result.append(numbers.copy())
    rev = numbers.copy()
    rev.reverse()
    result.append(rev)
    asc = [str(n) for n in range(1, length + 1, 2)]
    des = [str(n) for n in range(2, length + 1, 2)]
    des.reverse()
    result.append(asc + des)
    result.append(des + asc)
    while (count):
        random.seed()
        random.shuffle(numbers)
        result.append(numbers.copy())
        count -= 1
    return result

def sort_random_numbers(length, count):
    randoms = calc_random_numbers(length, count)
    total_moves = 0
    min_moves = sys.maxsize
    max_moves = 0
    for numbers in randoms:
        moves, error, check = sort_numbers(numbers, True)
        if error or check != 'OK':
            total_moves = 0
            min_moves = -1
            max_moves = -1
            break
        total_moves += moves
        if moves > max_moves:
            max_moves = moves
        if moves < min_moves:
            min_moves = moves
    mean_moves = total_moves / len(randoms)
    return mean_moves, min_moves, max_moves

def print_comb_numbers(length, rating_func=None):
    meanm, minm, maxm = sort_comb_numbers(length)
    if maxm < 0:
        rating = f'  [{RED}KO{RESET}]'
    elif rating_func is not None:
        rating = f'  {rating_func(maxm)}'
    else:
        rating = ''
    print(f'{BLUE}Combinaciones de {length}{RESET} --> {MAGENTA}{meanm:.2f}{RESET} [{GREEN}{minm}{RESET}-{RED}{maxm}{RESET}]{rating}')

def print_random_numbers(length, count, rating_func=None):
    meanm, minm, maxm = sort_random_numbers(length, count)
    if maxm < 0:
        rating = f'  [{RED}KO{RESET}]'
    elif rating_func is not None:
        rating = f'  {rating_func(maxm)}'
    else:
        rating = ''
    print(f'{BLUE}{length} aleatorios ({count} rep.){RESET} --> {MAGENTA}{meanm:.1f}{RESET} [{GREEN}{minm}{RESET}-{RED}{maxm}{RESET}]{rating}')

def main():
    print()
    for numbers in TESTS:
        moves, error, check = sort_numbers(numbers)
        if check == 'OK' or (check == 'Error' and error) or (check == '' and not error and not moves):
            check = f'[{GREEN}OK{RESET}]'
        else:
            check = f'[{RED}KO{RESET}]'
        moves = f'{MAGENTA}{moves}{RESET}' if not error else f'{CYAN}Error{RESET}'
        numbers = [f'{BLUE}{n}{RESET}' for n in numbers]
        print(f'push_swap({", ".join(numbers)}) --> {moves} {check}')
    print()
    print_all_comb_numbers(3)
    #print_all_comb_numbers(4)
    #print_all_comb_numbers(5)
    print()
    print_comb_numbers(2, lambda x:complex_message(2,x))
    print_comb_numbers(3, lambda x:points_message(points_3(x)))
    print_comb_numbers(4, lambda x:complex_message(4,x))
    print_comb_numbers(5, lambda x:points_message(points_5(x)))
    print_comb_numbers(6, lambda x:complex_message(6,x))
    print()
    print_random_numbers(17, 20, lambda x:complex_message(17,x))
    print_random_numbers(42, 20, lambda x:complex_message(42,x))
    print_random_numbers(100, 50, lambda x:points_message(points_100(x)))
    print_random_numbers(200, 20, lambda x:complex_message(200,x))
    print_random_numbers(500, 20, lambda x:points_message(points_500(x)))
    print()

if __name__ == "__main__":
    main()
