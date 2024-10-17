#include"seqList.h"

ostream& operator<<(ostream& cout, const student& st) {
	cout << "age:" << st.age << endl;
	cout << "name:" << st.name << endl;
	return cout;
}

