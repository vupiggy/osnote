string simplifyPath(string path) {
        int len = path.size();
        vector<string> vec;
        int i = 0, index = 0;
        while(i < len)
        {
		int j = path.find('//', i + 1);
		string tmp;
		if(j != string::npos)
			tmp = path.substr(i, j - i);
		else {tmp = path.substr(i, len); j = len;}
         
		if(tmp == "/");
		else if(tmp == "/.");
		else if(tmp == "/..")
                {if(!vec.empty())vec.pop_back();}
		else
			vec.push_back(tmp);
		i = j;
        }
        if(vec.empty())
		return "/";
        else {
		string res;
		for(int i = 0; i < vec.size(); i++)
			res += vec[i];
		return res;
        }
}
