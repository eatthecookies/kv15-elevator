#ifndef __CL_BASE__H
#define __CL_BASE__H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class cl_base;

#define SIGNAL_D(signal) (TYPE_SIGNAL)(&signal) 		// ���������������� ��� ���������� ��������� �� ����� ������� 
#define HANDLER_D(button_on_the_floor_has_been_pushed) (TYPE_HANDLER)(&button_on_the_floor_has_been_pushed)	// ���������������� ��� ���������� ��������� �� ����� �����������

typedef void (cl_base::* TYPE_SIGNAL) (string& s_message);
typedef void (cl_base::* TYPE_HANDLER) (string s_message);

struct o_sh                 	// ��������� ������� ����� �����
{
	TYPE_SIGNAL  p_signal;   	// ��������� �� ����� �������
	cl_base* p_target;   		// ��������� �� ������� ������
	TYPE_HANDLER p_handler;  	// ��������� �� ����� �����������
};

class cl_base
{
	string s_name; 							// ������������ �������
	int i_state;							// �������� ���������
	cl_base* p_head_object; 				// ��������� �� �������� ������
	vector < cl_base* > p_sub_objects;		// ��������� �� ����������� �������
	vector < o_sh* > connections;			// ������ ������ �������� � ������������
	int object_class;						// ����� ������
public:
	cl_base(cl_base* p_head_object, string s_name = "Base_object"); 	// ����������� ������ cl_base
	~cl_base();															// ���������� ������ cl_base		
	bool set_name(string s_new_name); 								   	// ����� ������� ������ ����� ��� �������
	string get_name();													// ����� ��������� ����� �������
	cl_base* get_head();												// ����� ��������� ��������� �� �������� ������	
	cl_base* get_sub_object(string s_name);							 	// ����� ��������� ��������� �� ����������� ������ �� �����

	int count_obj(string s_name); 							// �����, ������� ������������ ���������� ��������� �������� � ������ ������ �� ��������.
	cl_base* search_object(string s_name);				// ����� ������ ������� �� ������ �������� �� ����� (������ ������ ��������� �� �����)
	cl_base* find_object_from_current(string s_name);	// ����� ������ ������� �� ����� �� ����� ������ �������� �� �������� 
	cl_base* find_object_from_root(string s_name);		// ����� ������ ������� �� ����� �� ���� ������ �������� �� ����� 
	void print_tree(int spaces);						// ����� ������ ������ �������� ��������
	void print_tree_with_rns(int spaces);				// ����� ������ ������ �������� ��������
	void set_state(int i_state);						// ����� ��� ��������� ���������
	bool based_is_stated(); 							// �������� ����������� �������� ���� �� ������ ��������

	bool change_head_object(cl_base* new_head_object);  // ����� ��������������� ��������� �������
	void delete_sub_object(string name);				// ����� �������� ������������ ������� �� ������������
	cl_base* get_object_pointer(string coordinate);		// ����� ��������� ��������� �� ����� ������ �� �����������

	void set_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER p_handler); 		 // ������������ ����� ����� ���������
	void delete_connection(TYPE_SIGNAL p_signal, cl_base* p_object, TYPE_HANDLER p_ob_handler);	 // �������� ����� ����� ��������
	void emit_signal(TYPE_SIGNAL p_signal, string& msg);										 // ������ �������
	string get_absolute_path();																	 // ��������� ����������� ���� �������
	int get_object_class();																		 // ��������� ������ ������ �������
	void set_object_class(int n);																 // ������� �������� ���������� �������
	void set_all_state_on();																	 // ��������� �c�� ��������
	int get_state();
	void delete_links(cl_base* p_target);

	vector <cl_base*> get_sub_objects();
};



#endif