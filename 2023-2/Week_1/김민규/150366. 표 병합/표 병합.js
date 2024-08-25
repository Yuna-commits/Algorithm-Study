function solution(commands) {
    const result = []
    const table = Array(51).fill().map((_)=> Array(51).fill('EMPTY'))
    const root = Array(51).fill().map((_,i)=> Array(51).fill().map((_,j) => [i,j]))

    
    for(let command of commands){
        const [cmd, ...rest] = command.split(" ")
        
    function find(item){
        const [a, b] = item
        if([a,b].toString() === root[a][b].toString()){
            return [+a,+b]
        }
        root[a][b] = find(root[a][b])
        return root[a][b]
    }
    
    function update(item){
        const [a, b ,value] = item
        const target = find([a,b])
        
        for(let i =0; i<51; i++){
            for(let j=0; j<51; j++){
                if(root[i][j].toString() === target.toString()){
                    table[i][j] = value
                }
            }
        }
    }
    
    function replace(item){
        const [value1,value2] = item
            for(let i =0; i<51; i++){
                for(let j=0; j<51; j++){
                    if(table[i][j] === value1){
                        table[i][j] = value2
                    }
                }
        }
    }
    
        function merge(item){
            const [x1,y1,x2,y2] = item
            if(x1 === x2 && y1 === y2) return;
            
            const value = table[x1][y1] !== 'EMPTY' ? table[x1][y1] : table[x2][y2] 
            const root1 = find([x1,y1])
            const root2 = find([x2,y2])
            // console.log('item',item,'value',table[x1][y1],table[x2][y2],'root1',root1,'root2',root2)

            
            if(root1.toString() !== root2.toString()){
                root[x2][y2] = root1
            }
            
            for(let i =0; i<51; i++){
                for(let j=0; j<51; j++){
                    if(root[i][j].toString() === root2.toString()){
                        root[i][j] = root1
                    }
                    
                    if(root[i][j].toString() === root1.toString()){
                        table[i][j] = value
                    }
                }
        }
            
    }
        function unMerge(item){
            const [a,b] = item
            const value = table[a][b]
            const target =  find([a,b])
            
            for(let i =0; i<51; i++){
                for(let j=0; j<51; j++){
                    if(root[i][j].toString() === target.toString()){
                        table[i][j] = 'EMPTY'
                        root[i][j] = [i,j]
                    }
                }
            }
            table[a][b] = value
        }
        
        function print(item){
            const [a,b] = item
            result.push(table[a][b])
        }
        

        
        switch (cmd){
            case 'UPDATE':
                if(rest.length === 3) update(rest)
                else replace(rest)
                break
            case 'MERGE': 
                merge(rest)
                break
            case 'UNMERGE':
                unMerge(rest)
                break
            case 'PRINT':
                print(rest)
                break
        }

    }
    // console.log('tabe',result)
    return result 
}