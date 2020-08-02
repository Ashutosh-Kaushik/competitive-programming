set autoindent
let g:syntastic_cpp_compiler = 'clang++'
let g:syntastic_cpp_compiler_options = ' -std=c++17 -stdlib=libc++'
set shortmess=a
set cmdheight=2
set autowrite
nnoremap <C-c> :!g++ -std=c++11 % -Wall -g -o %.out && ./%.out<CR>
set runtimepath^=~/.vim/bundle/codeforces.vim-master
set runtimepath^=~/.vim/bundle/vim-std-io-master

filetype detect
set nocompatible
set exrc
set mouse=a
set tabstop=8
set shiftwidth=8

set smarttab
set autoindent
set smartindent
set cindent

set showcmd
set number
set autoread

set nowrap

map <F5> :<C-U>!g++ -O2 -DLOCAL -std=c++11 -Wall -Wextra -Wno-unused-result -static %:r.cpp -o %:r<CR>
map <F9> :<C-U>!./%:r<CR>
