<script>
  import { createEventDispatcher, onMount } from "svelte";
  import * as mathlive from 'mathlive'
  import * as database from "$lib/database.js";
  const dispatch = createEventDispatcher();
  const ENTER = 13;
  let mf;
  onMount(() => updateInput(atob(database.retrieve("q", ""))));
  function updateInput(value) {
    if (mf !== undefined) {
      mf.setValue(value);
    }
  }
  onMount(() => updateInput());
  function onKeyDown(event) {
    if(event.keyCode === ENTER && event.shiftKey) {
      event.preventDefault();
      dispatch('message', {
        cell: event.target.value
      });
    }
  }
</script>

<math-field on:keydown={onKeyDown} bind:this="{mf}"></math-field>

<style>
    math-field {
        border: 1px solid palegreen;
        padding: 0.5rem;
        font: inherit;
    }
</style>