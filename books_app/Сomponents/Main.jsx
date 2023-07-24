import React from "react";
import styles from "./Main.module.css"

function Main(){
    return (
    <div className={styles.header}>
        <div className={styles.row1}>
            <h1>A room without books is like <br /> a body without a soul.</h1>
        </div>
        <div className={styles.row2}>
            <h2>Find Your Book</h2>
            <div className={styles.search}>
                <input type="text" placeholder="Enter Your Book Name" />
                <button><i class="fa-solid fa-magnifying-glass"></i></button>
            </div>
        
        </div>

    </div>
    ) 


}

export default Main;