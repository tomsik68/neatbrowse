neatbrowse
==========
neatbrowse is a single-line file browser/chooser for *nix terminals.

This is how easily you can get to file which is at ~/projects/tests/progtest/problem1.c:
![gif animation](http://i.imgur.com/XAxxbfL.gif)

# Why would I want this?

1.) Shorten your cd commands!
Say you want to get to file `/home/user/my/dir/ect/or/y/numb/er/one/readme.txt`, but you're unsure about the path. What do you do?
Without neatbrowse:
	
	cd /home
	ls
	cd user
	ls
	cd my
	ls 
	cd dir
	ls
	cd ect
	ls
	cd or
	ls
	cd y
	ls

... come on, don't tell me you don't do this :) ...

With neatbrowse, this will become a one-liner: `cd $(neatbrowse)`. Using neatbrowse, you can choose files or directories.

2.) Because TAB-completion spams whole terminal.
Neatbrowse uses \r which should save your terminal space.

3) Lots of other commands that use <path_to_your_file>

# How to use neatbrowse

## Starting it
Invoke the binary using `neatbrowse [path_to_starting_directory]` or just `neatbrowse`.
You might need to use `./neatbrowse` if you don't have it in your `$PATH`...

## Output
Example output of neatbrowse: `->.<- .. .vim documents videos`
What you can see is a space-separated list of folders & files in your current directory. 
`->home<-` indicates, that a directory or file `home` is selected.

## Controlling neatbrowse
To move selection to the left, press `H`. To move right, press `L`.
To *O*pen a directory, press `O`.
To *A*ccept your selection, press `A`. After you accept the option, neatbrowse will print full path to accepted file/dir to stdout stream.
To cancel, press CTRL-C.

# How to compile

	make all

There's no install script atm, because I don't know how to create them :D You can create it and submit a PR if you're familiar with them.

# License
neatbrowse is under MIT license. See LICENSE for more information

# Some usage examples
You will usually want to use path from neatbrowse somewhere in further programs, so here are few useful examples(all in bash):
* CD - `cd $(neatbrowse)`
* vim/emacs - `vim $(neatbrowse)` or `emacs $(neatbrowse)`
* append selection to `$PATH` - `export PATH="$PATH:$(neatbrowse)"`

More examples can be found in EXAMPLES.md. You can also feel free to contribute more examples in a PR if you got something useful :)
