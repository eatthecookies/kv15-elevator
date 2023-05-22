#ifndef __CL_INPUT__H
#define __CL_INPUT__H

#include "cl_base.h"

class cl_input : public cl_base
{
public:
	cl_input(cl_base* p_head_object, string s_name = "input"); // ����������������� ����������� ������ cl_2

	void signal(string& s_message); 			// ����� ������ �������
	void read_command(string s_message);
	void elevator_has_been_called(string s_message); 			// ����� �����������

};



#endif
