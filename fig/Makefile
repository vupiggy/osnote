all: laddr.pdf page.pdf

%.pdf: %.tikz
	@printf "%-12s %s\n" "Tikzing " $<
	@tikzfile=$<; texfile=$${tikzfile%%.tikz}.tex; tikzfile=`basename $<`;		\
	 printf "\\\documentclass[tikz, border=10pt]{standalone}\n\n"	>$${texfile};	\
	 printf "\\\usetikzlibrary{calc,quotes,angles,shadows}\n"	>>$${texfile};	\
	 printf "\\\usepackage{amsthm}\n"				>>$${texfile};	\
	 printf "\\\usepackage{tkz-euclide}\n"				>>$${texfile};	\
	 printf "\\\usetkzobj{all}\n"					>>$${texfile};	\
	 printf "\\\usepackage{fontspec}\n"				>>$${texfile};	\
	 printf "\\\usepackage{xcolor}\n"				>>$${texfile};	\
	 printf "\\\begin{document}\n"					>>$${texfile};	\
	 printf "\\\input{$${tikzfile}}\n"				>>$${texfile};	\
	 printf "\\\end{document}\n\n"					>>$${texfile};	\
	 lualatex -interaction=nonstopmode -output-directory=./ $${texfile} $(OUTPUT)
