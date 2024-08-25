function solution(board) {


    let Tcheck = 0;
    let Fcheck =0;
    let Tdone = 0;
    let Fdone =0;
    let item =[...board[0].split(''),...board[1].split(''),...board[2].split('')]
    console.log(item)
    for(let i of item){
        if(i === 'O'){
            Tcheck++
        }
        if( i === 'X'){
            Fcheck++
        }
    }
    
    if(item[0]+item[1]+item[2]==='OOO'){
        Tdone++
    }
    if(item[3]+item[4]+item[5] === "OOO"){
        Tdone++
    }
    if(item[6]+item[7]+item[8] ==="OOO"){
        Tdone++
    }
    if(item[0]+item[3]+item[6]==='OOO'){
        Tdone++
    }
    if(item[1]+item[4]+item[7]==='OOO'){
        Tdone++
    }
    if(item[2]+item[5]+item[8] === 'OOO'){
        Tdone++
    }
    if(item[0]+item[4]+item[8]==="OOO"){
        Tdone++
    }
    if(item[2]+item[4]+item[6] === 'OOO'){
        Tdone++
    }
        if(item[0]+item[1]+item[2]==='XXX'){
        Fdone++
    }
    if(item[3]+item[4]+item[5] === "XXX"){
        Fdone++
    }
    if(item[6]+item[7]+item[8] ==="XXX"){
        Fdone++
    }
    if(item[0]+item[3]+item[6]==='XXX'){
        Fdone++
    }
    if(item[1]+item[4]+item[7]==='XXX'){
        Fdone++
    }
    if(item[2]+item[5]+item[8] === 'XXX'){
        Fdone++
    }
    if(item[0]+item[4]+item[8]==="XXX"){
        Fdone++
    }
    if(item[2]+item[4]+item[6] === 'XXX'){
        Fdone++
    }
    
    if(Tdone === Fdone && Tdone >0){
        return 0
    }
    if(Tdone>0 && Fdone>0){
        return 0
    }
    if(Tcheck === Fcheck ){
        if(Tdone>0){
            return 0
        }
    }
    if(Tcheck>Fcheck){
        if(Fdone>0){
            return 0
        }
    }
    if(Tcheck<Fcheck){
        return 0
    }
    if(Tcheck-Fcheck >1){
        return 0
    }

    return 1
}