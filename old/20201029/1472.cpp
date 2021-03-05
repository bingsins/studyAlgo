//hyunji.erica - 1472.Design Browser History
class BrowserHistory {
public:
    vector<string> history;
    int cur_index;
    
    BrowserHistory(string homepage) {
        history.clear();
        history.push_back(homepage);
        cur_index = 0;
    }
    
    void visit(string url) {
        history.erase(history.begin()+cur_index+1, history.end());
        history.push_back(url);
        cur_index++;
    }
    
    string back(int steps) {
        if( cur_index - steps > history.size() ){
            cur_index = 0;
        }
        else cur_index -= steps;
        return history[cur_index];
    }
    
    string forward(int steps) {
        if( cur_index + steps > history.size()-1){
            cur_index = history.size()-1;
        }
        else cur_index += steps;
        return history[cur_index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
