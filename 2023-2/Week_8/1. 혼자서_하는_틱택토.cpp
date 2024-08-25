#include <string>
#include <vector>

const int BOARD_SIZE = 3;

bool win_check(const std::vector<std::string> board, char c)
{
	// 가로줄 판단
	for (auto i = 0; i < BOARD_SIZE; i++)
		if (board[i][0] == c and board[i][1] == c and board[i][2] == c)
			return true;

	// 세로줄 판단
	for (auto i = 0; i < BOARD_SIZE; i++)
		if (board[0][i] == c and board[1][i] == c and board[2][i] == c)
			return true;

	// 주대각선 판단
	if (board[0][0] == c and board[1][1] == c and board[2][2] == c)
		return true;

	// 반대 대각선 판단
	if (board[2][0] == c and board[1][1] == c and board[0][2] == c)
		return true;

	return false;
}

int solution(std::vector<std::string> board)
{
	auto o_count = 0;
	auto x_count = 0;

	for (auto i = 0; i < BOARD_SIZE; i++)
		for (auto j = 0; j < BOARD_SIZE; j++)
			if (board[i][j] == 'O')
				o_count++;
			else if (board[i][j] == 'X')
				x_count++;

	// O의 개수와 X의 개수 차가 불가능할 때
	if (o_count - x_count < 0 or o_count - x_count > 1)
		return 0;

	// 동시에 승리했을 때
	if (win_check(board, 'O') and win_check(board, 'X'))
		return 0;

	// O가 승리했지만 O = X + 1가 아닐 때
	if (win_check(board, 'O') and o_count - x_count != 1)
		return 0;

	// X가 승리했지만 O의 개수와 X의 개수가 같지 않을 때
	if (win_check(board, 'X') and o_count - x_count != 0)
		return 0;

	return 1;
}