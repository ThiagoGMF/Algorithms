filetype detect
syntax on
set nocompatible
set exrc
set mouse=a
set tabstop=2
set shiftwidth=2
set softtabstop=2

set smarttab
set autoindent
set smartindent
set cindent

set showcmd
set autowrite
set autoread

set nowrap

set t_Co=256

map <F5> :<C-U>!g++ -O2 -DLOCAL -std=c++17 -Wall -Wextra -Wno-unused-result -static %:r.cpp -o %:r<CR>
map <F9> :<C-U>!./%:r<CR>

inoremap { {} 
inoremap " "" 
inoremap ' '' 
inoremap ( () 
inoremap [ []

autocmd BufNewFile *.cpp -r ~/projects/temp/template.cpp

