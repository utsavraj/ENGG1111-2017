#include <iostream>

using namespace std;

int
main ()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    {
      int a;
      string row1 = "";
      string row2 = "";
      string row3 = "";
      string row4 = "";
      for (int c = 0; c < 4; ++c)
	{
	  cin >> a;

	  switch (a)

	    {
	    case 8:
	      row1 += "****";
	      row2 += "****";
	      row3 += "****";
	      row4 += "****";
	      break;

	    case 10:
	      row1 += "****";
	      row2 += "*  *";
	      row3 += "*  *";
	      row4 += "****";
	      break;

	    case 9:
	      row1 += "    ";
	      row2 += " ** ";
	      row3 += " ** ";
	      row4 += "    ";
	      break;

	    case 11:
	      row1 += "    ";
	      row2 += "    ";
	      row3 += "    ";
	      row4 += "    ";
	      break;

	    case 7:
	      row1 += "    ";
	      row2 += "    ";
	      row3 += "****";
	      row4 += "****";
	      break;

	    case 6:
	      row1 += "****";
	      row2 += "****";
	      row3 += "    ";
	      row4 += "    ";
	      break;

	    case 5:
	      row1 += "  **";
	      row2 += "  **";
	      row3 += "  **";
	      row4 += "  **";
	      break;

	    case 4:
	      row1 += "**  ";
	      row2 += "**  ";
	      row3 += "**  ";
	      row4 += "**  ";
	      break;

	    case 3:
	      row1 += "****";
	      row2 += "*** ";
	      row3 += "**  ";
	      row4 += "*   ";
	      break;

	    case 2:
	      row1 += "****";
	      row2 += " ***";
	      row3 += "  **";
	      row4 += "   *";
	      break;

	    case 1:
	      row1 += "   *";
	      row2 += "  **";
	      row3 += " ***";
	      row4 += "****";
	      break;

	    default:
	      row1 += "*   ";
	      row2 += "**  ";
	      row3 += "*** ";
	      row4 += "****";
	    }
	}
      cout << row1 << endl << row2 << endl << row3 << endl << row4 << endl;
    }
  return 0;
}
