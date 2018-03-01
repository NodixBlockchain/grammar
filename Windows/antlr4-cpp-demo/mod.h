
class ArgKey
{
public:

	std::string	 name;
	std::string	 type;
};

class ArgChildKey :public ArgKey
{
public:
	int addOutput(std::string var_ref_name, std::string type, std::string key);
	int addInput(std::string var_ref_name, std::string type, std::string key);

	std::string			ref_name;
	std::list<ArgKey >	output;
	std::list<ArgKey >	input;
	std::list<ArgKey >	iter;
};

class FnCall
{
public:
	std::string func_name;
	std::string target;

};


class FnArg
{
public:

	unsigned int		native;
	std::string			type;
	std::string			id;

	std::list<FnCall>		fn_calls;
	std::list<ArgKey >		input;
	std::list<ArgKey >		output;

	std::list<ArgChildKey >	childkey;
	std::list<ArgChildKey >	addkey;

	std::list<ArgChildKey >	enumkey;

};


class FnDef
{
public:

	unsigned int		scriptable;
	unsigned int		has_non_native;
	std::string			name;
	std::list<FnArg >	args;

	int add_arg_call(std::string name, std::string fnname);

};

class FileDef
{
public:
	std::string		filePath;

	ANTLRInputStream	*input;
	CLexer				*lexer;
	CommonTokenStream	*tokens;
	CParser				*parser;
	tree::ParseTree		*tree;

};


class ModDef
{
public:

	std::list<FileDef>  files;
	std::list<FnDef *>	methods;


	void addFile(const char *path);
	void dump_fn(FnDef *fn);
	void dump();
	void visit();
	void parse();

}; 


