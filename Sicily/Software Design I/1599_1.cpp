#include "iostream"
#include "iomanip"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		double mat[2][2];
		cin >> mat[0][0] >> mat[0][1] >> mat[1][0] >> mat[1][1];
		
		double det = mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0]; // calculate its determinant

		if (det==0) // not invertible
			cout << "Not Invertible\n";
		else // invertible
		{
			cout << fixed << setprecision(3) << mat[1][1]/det << " " << -mat[0][1]/det << endl;
			cout << -mat[1][0]/det << " " << mat[0][0]/det << endl;
		}
		cout << endl;
	}
	return 0;
}
