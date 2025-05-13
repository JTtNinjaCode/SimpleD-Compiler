# Simple-D Compiler

### Dependencies
- yacc
- lex

## Run Locally
Clone the project.

```bash
  git clone https://github.com/JTtNinjaCode/SimpleD-Compiler.git
```

Go to the project directory.

```bash
  cd SimpleD-Compiler
```

build and run.

```bash
  make
  make run
```

All output files of example_code are located in the example_output directory. Intermediate compilation results and the program itself are placed in the build directory.

### Error Message
- (Error1.sd) type mismatch in operation.
- (Error2.sd) identifier conflict.
- (Error3.sd) variable type cant be void.
- (Error4.sd) array base type cant be void.
- (Error5.sd) identifier not exists.
- (Error6.sd) main func's return type should be void.
- (Error7.sd) main func shouldnt have param.
- (Error8.sd) main func not exists.

### Output format
Example1_sigma.sd.output

```
Start to parsing program:
[trans_unit]
	[const_decl] begin
		[literal   ] int literal: 10
		[var_decl  ] have initilizer
		[var_decl  ] ident: n
	[const_decl] end
	[literal   ] int literal: 0
	[var_decl  ] have initilizer
	[var_decl  ] ident: sum
	[var_decl  ] end
	[func_def  ] begin
	[func_def  ] func ident: main
		[fcstmt    ] begin
			[var_decl  ] not have initializer
			[var_decl  ] ident: index
			[var_decl  ] end
			[for       ]
			[IDNET     ] ident:index
			[literal   ] int literal: 1
			[ASSIGN    ]
			[IDNET     ] ident:index
			[IDNET     ] ident:n
			[LE        ]
			[IDNET     ] ident:index
			[DADD      ]
			[cstmt     ] begin
				[estmt     ] begin
					[IDNET     ] ident:sum
					[IDNET     ] ident:sum
					[IDNET     ] ident:index
					[ADD       ]
					[ASSIGN    ]
				[estmt     ] end

Symbol Table [Layer 3]================================================================
Name                 Type       Array    Function Const    ParamNum   AryDimNum 
======================================================================================
Symbol Table [Layer 2]================================================================
Name                 Type       Array    Function Const    ParamNum   AryDimNum 
index                int        no       no       no       0          0         
======================================================================================
Symbol Table [Layer 1]================================================================
Name                 Type       Array    Function Const    ParamNum   AryDimNum 
n                    int        no       no       yes      0          0         
main                 void       no       yes      no       0          0         
sum                  int        no       no       no       0          0         
======================================================================================

			[cstmt     ] end
			[estmt     ] begin
				[literal   ] string literal: The sum is 
// The following is omitted.
```

During parsing, information about the content being converted is printed. Additionally, every time a scope is exited, the state of the previous symbol table is printed. This allows us to track the lifetime of variables and check for naming conflicts.

### Todo List

const vs. constexpr: not the same!
global var decl -> constexpr
local var decl -> const