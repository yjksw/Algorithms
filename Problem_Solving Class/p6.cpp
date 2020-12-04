 #include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;

int sizePuzzle = 0;
int blockN = 0;

void print(vector<vector<int> > &puz) {
	for(int i=0;i<sizePuzzle;i++){
		for(int j=0;j<sizePuzzle;j++){
			printf("%d ", puz[i][j]);
		}
		printf("\n");
	}
	return;
}

void undoBlck(vector<vector<int> > &puz, vector<vector<int> >blck, int nblcks, int posX, int posY) {

	for(int r=0;r<blck.size();r++) {
		for(int c=0;c<blck[r].size();c++) {
			if(blck[r][c] == 0 || puz[posX+r][posY+c] != nblcks)
				continue;
			puz[posX+r][posY+c] = 0;
		}
	}

	return;
}

int putBlck(vector<vector<int> > &puz, vector<vector<int> > blck, int nblcks, int posX, int posY) {

	for(int r=0;r<blck.size();r++) {
		for(int c=0;c<blck[r].size();c++) {
			if(blck[r][c] == 0)
				continue; 
			if(puz[posX+r][posY+c]!=0){
				return 0;
			} 
			puz[posX+r][posY+c] = nblcks;
		}
	}

	return 1;
}

int arrangeBlck(vector<vector<int> > &sizes, vector<vector<vector<int> > > &blcks, vector<vector<int> > &puz, int nblcks){
	
	if(nblcks > blockN)
		return 1;

	for(int x=0;x<=sizePuzzle-sizes[nblcks-1][0];x++){
		for(int y=0;y<=sizePuzzle-sizes[nblcks-1][1];y++){
			int put = putBlck(puz, blcks[nblcks-1], nblcks, x, y);
			if(put == 1) {
				int success = arrangeBlck(sizes, blcks, puz, nblcks+1);
				if(success==1){
					return 1;
				}
			}
			undoBlck(puz, blcks[nblcks-1], nblcks, x, y);
		}
	}

	return 0;
}

int main() {

	int square = 0;
	scanf("%d", &blockN);

	vector<vector<int> > bSize(blockN, vector<int>(2, 0));
	vector<vector<vector<int> > > blocks;


	for(int b=0;b<blockN;b++) {
		int row, col;
		scanf("%d %d", &row, &col);
		bSize[b][0] = row;
		bSize[b][1] = col;

		vector<vector<int> > block(row, vector<int>(col, 0));

		for(int r=0;r<bSize[b][0];r++) {
			for(int c=0;c<bSize[b][1]; c++) {
				int fill = 0;
				scanf("%d", &fill);
				block[r][c] = fill;
				if(fill == 1) {
					square++;
				}
			}
		}

		blocks.push_back(block);
	}

	sizePuzzle = sqrt(square);
	if(square != (sizePuzzle*sizePuzzle)) {
		printf("No solution possible\n");
		return 0;
	}

	vector<vector<int> > puzzle(sizePuzzle, vector<int>(sizePuzzle, 0));
	int result = arrangeBlck(bSize, blocks, puzzle, 1);

	if(result == 1) {
		print(puzzle);
	} else if(result == 0) {
		printf("No solution possible\n");
	}

	return 0;
}

