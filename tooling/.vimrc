set nocompatible
filetype off
set rtp+=~/.vim/bundle/vundle/
call vundle#rc()

" This is the Vundle package, which can be found on GitHub.
" For GitHub repos, you specify plugins using the
" 'user/repository' format
Plugin 'gmarik/vundle'

" We could also add repositories with a ".git" extension
Plugin 'scrooloose/nerdtree.git'

" To get plugins from Vim Scripts, you can reference the plugin
" by name as it appears on the site
Plugin 'Buffergator'

Plugin 'honza/vim-snippets'
Plugin 'foosoft/vim-argwrap'
Plugin 'vim-airline/vim-airline'
Plugin 'altercation/vim-colors-solarized'
Plugin 'justinmk/vim-syntax-extra'
Plugin 'octol/vim-cpp-enhanced-highlight'
" Plugin 'Valloric/YouCompleteMe'

" Now we can turn our filetype functionality back on
filetype plugin indent on

map <F8> :w <CR> :!gcc % -o %< && ./%< <CR>
map <F9> :w <CR> :python % <CR>
map <F7> mzgg=G`z
map <C-b> :w <CR> :! load main.c<CR>
map <C-/> :w <CR> :! python3 % <CR>
set nu

"Key mapping for tabs
map <C-n> :NERDTreeToggle<CR>
map <C-Left> :tabprevious <CR>
map <C-Right> :tabnext <CR>
map <C-t> :tabnew <CR>

let g:ycm_confirm_extra_conf = 1
let g:ycm_auto_trigger = 0
let g:cpp_class_scope_highlight = 1
let g:cpp_member_variable_highlight = 1

syntax enable
set background=dark
colorscheme solarized
