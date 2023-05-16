
# кол-во клеток
board_size = 3
# игровое поле
board = [1, 2, 3, 4, 5, 6, 7, 8, 9]
def draw_board(): # вывод поля
    print("_" * 4 * board_size)
    for i in range(board_size):
        print((" " * 3 + "|") * 3)
        print("", board[i*3], "|", board[1 + i*3], "|", board[2 + i*3], "|")
        print(("_" * 3 + "|") * 3)
def game_step(index, char): # функция хода игрока
    if (index > 9 or index < 1 or board[index - 1] in ("X", "O")):
        return False
    board[index - 1] = char
    return True

def check_win(): # проверка победы одного из игроков
    win = False
    win_combination = (
        (0,1,2), (3,4,5), (6,7,8), # горизонтальные линии
        (0,3,6), (1,4,7), (2,5,8), # вертикальные линии
        (0,4,8), (2,4,6)           # диагональные линии
    )
    return win

def start_game():
    current_player = "X" # текущий игрок
    step = 1 # номер шага
    draw_board()
    while (step < 10) and (check_win() == False):
        index = input ("Ходит игрок " + current_player + ". Введите номер поля( 0 - выход из игры): ")
        if index == "0":
            break

        if (game_step(int(index), current_player)): # если получилось сделать шаг
            print ("Удачный ход")
            if current_player == "X":
                current_player = "O"
            else:
                current_player = "X"
            draw_board()
            step += 1 # увеличение номера шага
        else:
            print("Неверный номер. Повторите")

print("Добро пожаловать в игру Крестики-нолики")
start_game()