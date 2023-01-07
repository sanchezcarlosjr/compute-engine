<script>
  import "../app.css";
  import MathInput from "$lib/mathinput.svelte";
  import MathField from "$lib/mathfield.svelte";
  import NaturalLanguageInput from "$lib/natural-language-input.svelte";
  import { onMount } from "svelte";
  import * as database from "$lib/database.js";
  export let computeEngineAlpha;
  let kindOfInput = "0";
  let result = "";
  onMount(() => kindOfInput = database.retrieve("k", "0"));
  function handleEnter(event) {
    const cell = event.detail.cell.trim();
    if (cell === "") {
      result = "";
      return;
    }
    result = computeEngineAlpha.interpret(cell+"\n");
    database.save("q", btoa(cell));
    database.save("k", kindOfInput);
  }
</script>


<div class="w-full">
  {#if kindOfInput === "0"}
    <NaturalLanguageInput on:message={handleEnter}/>
  {:else}
    <MathInput on:message={handleEnter}/>
  {/if}
  <ul class="items-center text-sm font-medium text-gray-900 bg-white sm:flex mt-0.5">
    <li>
      <div class="flex items-center">
        <input value="0"  bind:group={kindOfInput} checked id="natural-language"  type="radio" name="choices">
        <label for="natural-language" class="w-full py-3 ml-2 text-sm font-medium text-gray-900 dark:text-gray-300">Natural Language</label>
      </div>
    </li>
    <li>
      <div class="flex items-center pl-3">
        <input value="1"  bind:group={kindOfInput} id="latex" type="radio" name="choices">
        <label for="latex" class="w-full py-3 ml-2 text-sm font-medium text-gray-900 dark:text-gray-300">Latex</label>
      </div>
    </li>
  </ul>
  <MathField bind:value={result}></MathField>
</div>



