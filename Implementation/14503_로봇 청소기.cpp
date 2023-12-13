#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define NO_CLEAN 0
#define WALL     1
#define CLEAN    2

#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

vector<vector<int>>    Room;                     // 0: No clean, 1: Wall
int                    RoomRow, RoomCol;         // 3~50
int                    RVCStartRow, RVCStartCol; // RVC: Robotic Vacuum Cleaner
int                    RVCDir;                   // 0: North, 1: East, 2: South, 3: West
int                    NumberOfCleaning = 0;
vector<pair<int, int>> MovingBundle {
    {-1,  0}, // North
    { 0,  1}, // East
    { 1,  0}, // South
    { 0, -1}  // West
};
void Cleaning(const int& TargetRow, const int& TargetCol);

int main()
{
    cin >> RoomRow >> RoomCol >> RVCStartRow >> RVCStartCol >> RVCDir;
    Room = vector<vector<int>>(RoomRow, vector<int>(RoomCol, 0));
    for (auto& OneRow : Room)
    {
        for (auto& Element : OneRow)
        {
            cin >> Element;
        }
    }

    // First cleaning
    Cleaning(RVCStartRow, RVCStartCol);

    int CurrentRow = RVCStartRow;
    int CurrentCol = RVCStartCol;
    while (true)
    {
        bool        BackwardFlag = true;
        vector<int> DirectionBundleForTurningCCW90 {(RVCDir + 3) % 4, (RVCDir + 2) % 4, (RVCDir + 1) % 4, RVCDir};

        for (const auto& TurningCCW90Dir : DirectionBundleForTurningCCW90)
        {
            int ForwardRow = CurrentRow + MovingBundle[TurningCCW90Dir].first;
            int ForwardCol = CurrentCol + MovingBundle[TurningCCW90Dir].second;

            if (Room[ForwardRow][ForwardCol] == NO_CLEAN)
            {
                CurrentRow   = ForwardRow;
                CurrentCol   = ForwardCol;
                RVCDir       = TurningCCW90Dir;
                BackwardFlag = false;

                Cleaning(CurrentRow, CurrentCol);

                break;
            }
        }

        if (BackwardFlag)
        {
            int BackwardRow = CurrentRow - MovingBundle[RVCDir].first;
            int BackwardCol = CurrentCol - MovingBundle[RVCDir].second;
            if (Room[BackwardRow][BackwardCol] == WALL)
            {
                cout << NumberOfCleaning << endl;
                return 0;
            }
            else
            {
                CurrentRow = BackwardRow;
                CurrentCol = BackwardCol;
                if (Room[CurrentRow][CurrentCol] == NO_CLEAN)
                {
                    Cleaning(CurrentRow, CurrentCol);
                }
            }
        }
    }
}

void Cleaning(const int& TargetRow, const int& TargetCol)
{
    Room[TargetRow][TargetCol] = CLEAN;
    NumberOfCleaning++;
}